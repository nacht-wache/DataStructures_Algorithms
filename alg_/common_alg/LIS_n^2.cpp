#include <vector>
#include <algorithm>

using ll = long long;

struct Solution {
  static ll task(std::vector<ll> nums) {
	std::vector<ll> len(nums.size(), 1);

	ll ans{0};
	for (size_t i{1}; i < nums.size(); ++i) {
	  for (size_t j{0}; j < i; ++j) {
		if (nums[j] < nums[i]) {
		  len[i] = std::max(len[i], len[j] + 1);
		}
		ans = std::max(ans, len[i]);
	  }
	}

	return ans;
  }
};

