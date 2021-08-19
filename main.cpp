#include <iostream>
#include <LIS_nlogn.cpp>

int main() {
  std::vector<ll> v{INT64_MAX, INT64_MIN, INT64_MIN, INT64_MIN, INT64_MIN};
  auto begin = std::lower_bound(v.rbegin(), v.rend(), 1);
  std::advance(begin, 0);
  std::cout << std::distance(v.rend(), v.rend()) << ' ' << std::distance(v.rend(), begin);
}
