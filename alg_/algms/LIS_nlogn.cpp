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

	std::reverse(nums.begin(),nums.end());

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

  static std::vector<ll> task_alg(const std::vector<ll> &numbers) {
	assert(numbers.size() < INT16_MAX);
	std::vector<ll> result(1, INT64_MIN);
	result.push_back(numbers[0]);
	result.resize(numbers.size() + 1, INT64_MAX);

	//храним -1, т.к. distance не будет равен -1 (assert)
	std::vector<ll> dist_to_prev(result.size(), -1);

	for (auto num = std::next(numbers.begin()); num != numbers.end(); ++num) {

	  if (*num == INT64_MAX) {
		break;
	  }

	  auto num_to_exchange = std::upper_bound(result.begin(), result.end(), *num);
	  auto upper_distance = std::distance(result.begin(), num_to_exchange);
	  auto prev_to_exchange = std::prev(num_to_exchange);

	  if (*prev_to_exchange < *num
		  && *num < *num_to_exchange) {

		*num_to_exchange = *num;
		auto distance = dist_to_prev.begin();
		std::advance(distance, upper_distance);
		assert(std::distance(numbers.begin(), num) > 0);
		*distance = std::distance(numbers.begin(), num);

	  }
	}

	std::vector<ll> to_return;
	for (auto &i : dist_to_prev) {
	  if (i != -1) {
		to_return.push_back(i);
	  }
	}
	return to_return;
  }

  static std::vector<ll> task(size_t number_count, ll q, ll w, ll e, ll r, ll t) {
	std::vector<ll> numbers;
	numbers.reserve(number_count);
	numbers.push_back(q);
	numbers.push_back(w);
	numbers.push_back(e);
	numbers.push_back(r);
	numbers.push_back(t);
	/*numbers.push_back(y);
	numbers.push_back(u);
	numbers.push_back(i);
	numbers.push_back(o);
	numbers.push_back(p);*/

	return task_alg(numbers);
  }
};

#endif //ARRAY_LIMIT
