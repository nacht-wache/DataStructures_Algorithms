#include <algorithm>
#include <cstddef>
#include <string>

int recursion(std::vector<std::vector<int>> &matrix, const std::string &str1, const std::string &str2) {
  size_t size1 = str1.size();
  size_t size2 = str2.size();
  if (str1.empty() || str2.empty())
	return size1 + size2;

  for (int i{0}; i < matrix.size(); ++i)
	matrix[i][0] = i;

  for (int j{0}; j < matrix[0].size(); ++j)
	matrix[0][j] = j;

  for (int i{1}; i < matrix.size(); ++i) {
	for (int j{1}; j < matrix[0].size(); ++j) {
	  int c = str1[i - 1] != str2[j - 1];
	  int i_j = matrix[i - 1][j] + 1;
	  int ij_ = matrix[i][j - 1] + 1;
	  int i_j_ = matrix[i - 1][j - 1] + c;
	  matrix[i][j] = std::min({i_j, ij_, i_j_});
	}
  }
  return matrix[str1.size()][str2.size()];
}

int get_levenshtein_distance(const std::string &str1, const std::string &str2) {
  std::vector<int> M(str2.size() + 1, INT32_MAX);
  std::vector<std::vector<int>> matrix(str1.size() + 1);
  for (auto &i : matrix)
	i = M;

  return recursion(matrix, str1, str2);
}
