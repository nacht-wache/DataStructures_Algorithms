#ifndef DS_SORTING_ALG_MERGESORT_INVERSE_COUNT_H_
#define DS_SORTING_ALG_MERGESORT_INVERSE_COUNT_H_

#include <iostream>
#include <vector>

template <typename It>
long merge(It _first, It _middle, It _last) {
  std::vector<int> left(_first, _middle);
  std::vector<int> right(_middle, _last);
  auto left_runner = left.begin();
  auto right_runner = right.begin();
  long inverse_count = 0;
  for (; _first != _last; ++_first) {
	if (right_runner == right.end()) {
	  *_first = *(left_runner++);
	} else if (left_runner == left.end())
	  *_first = *(right_runner++);
	else if (*left_runner > *right_runner) {
	  inverse_count += left.end() - left_runner;
	  *_first = *(right_runner++);
	} else
	  *_first = *(left_runner++);
  }
  return inverse_count;
}

template <typename It>
long merge_sort(It _first, It _last) {
  auto distance = std::distance(_first, _last);
  if (distance < 2)
	return 0;
  auto middle = _first;
  std::advance(middle, distance / 2);
  auto inverse_count = merge_sort(_first, middle);
  inverse_count += merge_sort(middle, _last);
  inverse_count += merge(_first, middle, _last);
  return inverse_count;
}

#endif //DS_SORTING_ALG_MERGESORT_INVERSE_COUNT_H_
