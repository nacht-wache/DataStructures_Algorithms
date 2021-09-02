#include <vector>
#include <algorithm>
#include <iostream>

int stairs(std::vector<int> &A) {
  std::vector<int> B(A.size() + 1);
  B[0] = 0;
  B[1] = A[0];
  for (int i{1}; i < A.size(); ++i) {
	B[i + 1] = std::max((A[i] + B[i - 1]), (A[i] + B[i]));
  }

  return B.back();
}