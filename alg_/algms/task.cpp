#include "task.hpp"
/*
8
5 3 4 4 2 5 5 5 5

 6
 1 1 2 3 2 6
 */

void task_alg(const std::vector<ll>& numbers) {
  assert(numbers.size() < INT16_MAX);
  std::vector<ll> result(1, ARRAY_LIMIT);
  result.push_back(numbers[0]);
  result.resize(numbers.size() + 1, INT64_MAX);

  std::map<ll, ll> count;
  //храним -1, т.к. distance не будет равен -1 (assert)
  std::vector<ll> dist_to_prev(result.size(), -1);
  dist_to_prev[1] = 1;

  for (auto num = std::next(numbers.begin()); num != numbers.end(); ++num) {

	if (*num == INT64_MAX) {
	  break;
	}

	auto num_to_exchange = std::upper_bound(result.begin(), result.end(), *num);
	auto upper_distance = std::distance(result.begin(), num_to_exchange);
	auto prev_to_exchange = std::prev(num_to_exchange);

	if (*prev_to_exchange < *num
		&& *num < *num_to_exchange) {

	  *num_to_exchange = *num;
	  auto distance = dist_to_prev.begin();
	  std::advance(distance, upper_distance);
	  assert(std::distance(numbers.begin(), num) > 0);
	  *distance = std::distance(numbers.begin(), num);

	}
  }

  for (auto it = std::next(dist_to_prev.begin()); *it != -1; ++it) {
	auto print = numbers.begin();
	std::advance(print, *it);
	std::cout << *print << ' ';
  }
}

void task() {
  size_t number_count;
  std::cin >> number_count;
  std::vector<ll> numbers(number_count);
  for (auto& number : numbers) {
	std::cin >> number;
  }
  task_alg(numbers);
}

void adder() {
  int a, b;
  std::cin >> a >> b;
  std::cout << a + b;
}

