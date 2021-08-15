#include <iosfwd>
#include <vector>

using ll = long long;

ll FibTD_algh(std::vector<ll>& v, ll n) {
  ll i = n != 1 && n != 0 ? i = n - 1 : n;
  if (v[i] == -1) {
	if (n <= 1) {
	  v[n] = n;
	} else {
	  v[i] = FibTD_algh(v, n - 1) + FibTD_algh(v, n - 2);
	}
  }
  return v[i];
}

void FibTD() {
  std::vector<ll> Fibonacci;
  ll sz = 10;
  for(; sz < 50; ++sz) {
	Fibonacci.resize(sz, -1);
	std::cout << FibTD_algh(Fibonacci, sz) << ' ';
  }
}
