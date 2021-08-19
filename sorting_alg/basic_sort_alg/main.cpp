#include <iostream>
#include <vector>

void insertion_sort() {
  std::vector<int> v{31, 41, 59, 26, 41, 58, 7, 10};
  for (int i = 1; i < v.size(); ++i) {
	int key = v[i];
	int j = i - 1;
	while (j >= 0 && v[j] < key) { // comparing ( '<' or '>')
	  v[j + 1] = v[j];
	  --j;
	}
	v[j + 1] = key;
  }

  for (auto &i : v) {
	std::cout << i << ' ';
  }
}

int main() {
  insertion_sort();
}
