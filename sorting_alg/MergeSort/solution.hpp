#include <algorithm>
#include <iostream>
#include <vector>

using iter = std::vector<int>::iterator;
static unsigned long pairs = 0;

void merge(std::vector<int> &arr, iter begin, iter mid, iter end) {
  std::vector<int> left, right, result;
  for (auto it = begin; it != std::next(mid); ++it) {
	left.push_back(*it);
  }
  for (auto it = std::next(mid); it != std::next(end); ++it) {
	right.push_back(*it);
  }
  auto it_left = left.begin(), it_right = right.begin();
  while (it_left != left.end() && it_right != right.end()) {
	if (*it_right < *it_left) {
	  result.push_back(*it_right);
	  pairs += left.size() - std::distance(left.begin(), it_left);
	  ++it_right;
	} else {
	  result.push_back(*it_left);
	  ++it_left;
	}
  }

  result.insert(result.end(), it_left, left.end());
  result.insert(result.end(), it_right, right.end());

  std::move(result.cbegin(), result.cend(), begin);
}

void merge_sort(std::vector<int> &arr, iter begin, iter end) {
  if (begin < end) {
	auto mid = begin;
	std::advance(mid, (std::distance(begin, end) - 1) / 2);
	merge_sort(arr, begin, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
  }
}