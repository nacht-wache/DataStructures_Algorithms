//#include "solution.hpp"
//#include "template_based.hpp"
#include <list>
#include <algorithm>
#include "inverse_count.hpp"
#include <chrono>



int main(int argc, char* argv[]) {
  size_t size{0};
  std::cin >> size;
  std::vector<int> arr(size);
  size_t sz {3};
  std::for_each(arr.begin(), arr.end(), [&sz](int& y) {
    std::cin >> y;
  });
  auto start = std::chrono::steady_clock::now();

  for (auto i : arr) {
	std::cout << i << ' ';
  }

  std::cout << '\n' <<  merge_sort(arr.begin(), arr.end());;

  auto end = std::chrono::steady_clock::now();
  auto seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << '\n';


  std::cout << seconds.count();
}