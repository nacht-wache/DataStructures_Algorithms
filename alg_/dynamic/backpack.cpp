#include <vector>
#include <algorithm>

int backpack(int S, std::vector<int> &weight) {
  std::vector<int> F(S + 1, 0);
  F[0] = 1;
  std::vector<int> F_new = F;

  std::sort(weight.begin(), weight.end());

  for (int i{0}; i < weight.size(); ++i) {
	for (int j{weight[i]}; j < S + 1; ++j) {
	  if (F[j - weight[i]] == 1)
		F_new[j] = 1;
	}
	F = F_new;
  }

  for (auto it = F.crbegin(); it != F.crend(); ++it) {
	if (*it == 1)
	  return static_cast<int>(std::distance(it, F.crend() - 1));
  }
  return weight[0];
}