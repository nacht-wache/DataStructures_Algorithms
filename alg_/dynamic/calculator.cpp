#include <vector>
#include <iostream>
#include <algorithm>

# define INT32_MAX (2147483647)

std::vector<std::pair<int, int>> find(const int n) {
  std::vector<std::pair<int, int>> steps(n + 1,
										 {0, INT32_MAX});
  int one = 1;
  steps[1].second = 0;
  for (int i{1}; i < n; ++i) {
	int x_1, x_2, x_3;
	x_1 = i + 1;
	x_2 = i * 2;
	x_3 = i * 3;
	if (x_1 < steps.size()) {
	  if (steps[x_1].second > steps[i].second + 1) {
		steps[x_1].second = steps[i].second + 1;
		steps[x_1].first = i;
	  }
	}
	if (x_2 < steps.size()) {
	  if (steps[x_2].second > steps[i].second + 1) {
		steps[x_2].second = steps[i].second + 1;
		steps[x_2].first = i;
	  }
	}
	if (x_3 < steps.size()) {
	  if (steps[x_3].second > steps[i].second + 1) {
		steps[x_3].second = steps[i].second + 1;
		steps[x_3].first = i;
	  }
	}
  }
  return steps;
}

std::vector<int> calculator(const int n) {
  std::vector<std::pair<int, int>> steps = find(n);
  std::vector<int> answer;
  answer.reserve(steps[n].second);
  answer.push_back(n);
  int i = steps[n].first;
  while (i != 0) {
	answer.push_back(i);
	i = steps[i].first;
  }
  std::reverse(answer.begin(), answer.end());
  return answer;
}