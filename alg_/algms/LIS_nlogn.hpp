#ifndef ARRAY_LIMIT
#define ARRAY_LIMIT (100000)

#include <algorithm>
#include <iostream>
#include <map>
#include <cassert>
#include <vector>

using ll = long long;

struct Solution {

  static std::vector<ll> task_alg(const std::vector<ll>& numbers);

  static std::vector<ll> task(size_t number_count, ll q, ll w, ll e, ll r, ll t);
};

#endif //ARRAY_LIMIT
