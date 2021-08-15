#include <vector>
#include <random>
#include <algorithm>

using ll = long long;

void make_random(std::vector<ll>& v) {
  std::random_device rnd_device;
  std::mt19937 mersenne_engine{rnd_device()};
  std::uniform_int_distribution<ll> dist{1, 10};

  auto gen = [&dist, &mersenne_engine]() {
	return dist(mersenne_engine);
  };

  std::generate(begin(v), end(v), gen);

  for (auto i : v) {
	std::cout << i << ' ';
  }

  std::cout << '\n';
}

ll LISBottomUp_algh(std::vector<ll>& A) {
  std::vector<ll> D(A.size());
  D[0] = 1;
  for (size_t i{1}; i < A.size();
	   ++i) { // starts with the second element [1] (excluding overflowing of size_t (0 - 1))
	D[i] = 1;
	for (size_t j{0}; j <= i - 1; ++j) { // forgot <=; starts with first element [0]
	  if (A[j] % A[i]  && D[j] + 1 > D[i]) { // if the number is less then me and it's LIS plus me (+1) bigger than mine
		D[i] = D[j] + 1; // mine LIS = his LIS plus me
	  }
	}
  }
  ll max{0};
  return max;
}

void LISBottomUp() {
  ll sz = 5;
  std::vector<ll> v(sz);
  make_random(v);
  std::cout << LISBottomUp_algh(v);
}