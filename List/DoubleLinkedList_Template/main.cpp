#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

static unsigned long pairs = 0;
using iter = std::vector<int>::iterator;

/*template <typename It>
std::vector<typename It::value_type> merge(const It begin, const It mid, const It end) {

  std::vector<typename It::value_type> v;
  It it_l{begin}, it_r{mid};
  const It it_mid{mid}, it_end{end};

  while (it_l != it_mid && it_r != it_end) {
	if (*it_l <= *it_r) {
	  v.push_back(*it_l);
	  ++it_l;
	} else {
	  v.push_back(*it_r);
	  std::for_each(begin, end, [it_r](int x) {
		std::cout << x << ' ';
	  });
	  std::cout << "it_r = " << *it_r << '\n';
	  It temp_begin = {begin};
	  while (*temp_begin == *it_r) { ++temp_begin;}
	  pairs += it_r - temp_begin;
	  ++it_r;
	}
  }

  v.insert(v.end(), it_l, it_mid);
  v.insert(v.end(), it_r, it_end);

  return v;
}

template <typename It>
void merge_sort(It begin, It end) {
  auto size = std::distance(begin, end);
  if (size < 2)
	return;

  auto mid = std::next(begin, size / 2);
  merge_sort(begin, mid);
  merge_sort(mid, end);

  auto&& v = merge(begin, mid, end);
  std::move(v.cbegin(), v.cend(), begin);
}*/

void merge(std::vector<int> &arr, iter begin, iter mid, iter end) {
  std::vector<int> result;;
  result.reserve(arr.size());
  int i{0};
  while (begin <= mid && std::next(mid) <= end) {
	if (*std::next(mid) < *begin) {
	  result.push_back(*std::next(mid));
	  //int temp = *std::next(mid);
	  //arr.erase(std::next(mid));
	  //arr.insert(begin, temp);
	  pairs += std::distance(begin, std::next(mid));
	  ++mid;
	  ++i;
	  ++begin;
	} else {
	  result.push_back(*begin);
	  ++begin;
	}
  }

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

int main(int argc, char *argv[]) {
  size_t size{0};
  std::cin >> size;
  std::vector<int> arr(size);
  std::for_each(arr.begin(), arr.end(), [](int &y) {
	std::cin >> y;
  });
  auto start = std::chrono::steady_clock::now();

  merge_sort(arr, arr.begin(), std::prev(arr.end()));

  for (auto i : arr) {
	std::cout << i << ' ';
  }

  std::cout << '\n' << pairs;

  auto end = std::chrono::steady_clock::now();
  auto seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << '\n';

  std::cout << seconds.count();
}


/*template <typename T>
void SelectionSort(std::vector<T>& v) {
  if (v.empty()) {
	return;
  }
  for (size_t idx_i{0}; idx_i < v.size() - 1; ++idx_i) {

	size_t min_idx{idx_i};

	for (size_t idx_j{idx_i + 1}; idx_j < v.size(); ++idx_j) {
	  if (v[idx_j] < v[min_idx]) {
		min_idx = idx_j;
	  }
	}
	std::swap(v[idx_i], v[min_idx]);
  }

}*/