#include "task.hpp"

std::vector<ll> task_alg(const std::vector<ll>& numbers) {
  assert(numbers.size() < INT16_MAX);
  std::vector<ll> result(1, INT64_MIN);
  result.push_back(numbers[0]);
  result.resize(numbers.size() + 1, INT64_MAX);

  std::map<ll, ll> count;
  //храним -1, т.к. distance не будет равен -1 (assert)
  std::vector<ll> dist_to_prev(result.size(), -1);

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

  std::vector<ll> to_return;
  for(auto& i : dist_to_prev) {
    if(i != -1) {
      to_return.push_back(i);
    }
  }
  return to_return;
}

std::vector<ll> task(size_t number_count, ll q, ll w, ll e, ll r, ll t) {
  std::vector<ll> numbers;
  numbers.reserve(number_count);
  numbers.push_back(q);
  numbers.push_back(w);
  numbers.push_back(e);
  numbers.push_back(r);
  numbers.push_back(t);
  /*numbers.push_back(y);
  numbers.push_back(u);
  numbers.push_back(i);
  numbers.push_back(o);
  numbers.push_back(p);*/

  return task_alg(numbers);
}

