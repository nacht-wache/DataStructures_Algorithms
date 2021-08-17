#include <vector>
#include <random>
#include <algorithm>

#ifndef ARRAY_LIMIT
#define ARRAY_LIMIT (10)

using ll = long long;

void make_random(std::vector<ll>& v) {
  std::random_device rnd_device;
  std::mt19937 mersenne_engine{rnd_device()};
  std::uniform_int_distribution<ll> dist{1, 10};

  auto gen = [&dist, &mersenne_engine]() {
	return dist(mersenne_engine);
  };

  std::generate(begin(v), end(v), gen);
}

class Solution {
  static ll task() {
	std::vector<ll> nums(ARRAY_LIMIT);
	make_random(nums);
	std::vector<ll> len(nums.size(), 1);

	ll ans {0};
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

#endif //ARRAY_LIMIT
