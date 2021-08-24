#include <algorithm>
#include <vector>
#include <map>

using ll = long long;

struct Solution {

  static std::vector<ll> foo(std::vector<ll> &nums) {
	int LIS_size{1};
	std::reverse(nums.begin(), nums.end());

	std::vector<ll> min_num(1, INT64_MIN);
	min_num.resize(nums.size() + 1, INT64_MAX);

	std::vector<ll> poses(nums.size() + 1);
	std::vector<ll> anc(nums.size() + 1, -1);

	poses[0] = -1;
	poses[1] = 1;
	min_num[1] = nums[0];

	for (auto iter = ++nums.begin(); iter != nums.end(); ++iter) {
	  auto it_num = std::upper_bound(min_num.begin(), min_num.end(), *iter);
	  LIS_size = std::max(LIS_size, static_cast<int>(std::distance(min_num.begin(), it_num) + 1));

	  if (*std::prev(it_num) <= *it_num && *iter < *it_num) {
		*it_num = *iter;

		auto offset_min_num = std::distance(min_num.begin(), it_num);
		auto offset_nums = std::distance(nums.begin(), iter) + 1;

		auto offset_pos = poses.begin();
		std::advance(offset_pos, offset_min_num);
		*offset_pos = offset_nums;

		auto offset_anc = anc.begin();
		std::advance(offset_anc, offset_nums);
		*offset_anc = *std::prev(offset_pos);
	  }
	}

	if (LIS_size == 1) return {1};
	std::vector<ll> answer;
	answer.reserve(LIS_size);
	ll pos = poses[LIS_size - 1];
	answer.push_back(nums.size() + 1 - pos);
	while (anc[pos] != -1) {
	  answer.push_back(nums.size() + 1 - anc[pos]);
	  pos = anc[pos];
	}

	return answer;
  }
};