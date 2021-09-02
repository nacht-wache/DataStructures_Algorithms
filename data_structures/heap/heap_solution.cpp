#include <vector>
#include <iostream>
#include <queue>

using ll = long long;

struct stl_solution {
  void foo();

 private:
  std::priority_queue<ll, std::vector<ll>, std::less<>> max_heap;
  std::vector<ll> output;

 private:
  void extract_max();
  void insert();
  static bool is_insert(std::string &prompt);
};

void stl_solution::extract_max() {
  output.push_back(max_heap.top());
  max_heap.pop();
}

void stl_solution::insert() {
  ll x;
  std::cin >> x;
  max_heap.push(x);
}

bool stl_solution::is_insert(std::string &prompt) {
  std::cin >> prompt;
  return prompt == "Insert";
}

void stl_solution::foo() {
  int n;
  std::cin >> n;

  std::string prompt;
  for (int i{0}; i < n; ++i) {
	is_insert(prompt)
	? insert()
	: extract_max();
  }
}

