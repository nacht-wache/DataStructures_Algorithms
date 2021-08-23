#ifndef ARRAY_LIMIT
#define ARRAY_LIMIT (10)

#include <algorithm>
#include <cassert>
#include <vector>
#include <map>

using ll = long long;

struct Solution {

  static std::vector<ll> foo(std::vector<ll> &nums) {
	ll LIS_size{1};
	std::vector<ll> LIS(nums.size(), INT64_MAX);
	std::vector<ll> poses(nums.size(), INT64_MAX);
	std::map<ll, std::pair<ll, std::vector<ll>>> counter;

	std::reverse(nums.begin(), nums.end());

	for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
	  auto it = std::upper_bound(LIS.begin(), LIS.end(), *iter);
	  LIS_size = std::max(LIS_size, static_cast<ll>(std::distance(LIS.begin(), it) + 1));

	  auto offset_LIS = std::distance(LIS.begin(), it);
	  auto offset_nums = std::distance(nums.begin(), iter) + 1;
	  auto pos = poses.begin();
	  std::advance(pos, offset_LIS);

	  ++counter[*iter].first;
	  counter[*iter].second.push_back(offset_nums);

	  if (counter[*iter].first > LIS_size) {
		std::fill_n(LIS.begin(), ++LIS_size, *iter);
		std::copy_n(counter[*iter].second.begin(), LIS_size, poses.begin() + 1);
		break;
	  }

	  if (offset_LIS + 1 == nums.size() || *std::next(pos) > offset_nums) {
		*it = *iter;
		*pos = offset_nums;
	  }

	}

	std::vector<ll> answer;
	answer.reserve(poses.size());
	for (auto it = poses.begin(); it != poses.end() && *it != INT64_MAX; ++it) {
	  answer.push_back(*it);
	}

	return answer;
  }
};

#endif //ARRAY_LIMIT