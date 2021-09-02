#include <vector>
#include <iostream>
#include <queue>

using ll = long long;

struct stl_solution {
  std::vector<ll> foo();

 private:
  std::priority_queue<ll, std::vector<ll>, std::less<>> huffman_table;
  std::vector<ll> output;

 private:
  void extract_max();
  void insert();
  static bool is_insert(std::string &prompt);
};

void stl_solution::extract_max() {
  output.push_back(huffman_table.top());
  huffman_table.pop();
}

void stl_solution::insert() {
  ll x;
  std::cin >> x;
  huffman_table.push(x);
}

bool stl_solution::is_insert(std::string &prompt) {
  std::cin >> prompt;
  return prompt == "Insert";
}

std::vector<ll> stl_solution::foo() {
  int n;
  std::cin >> n;

  std::string prompt;
  for (int i{0}; i < n; ++i) {
	is_insert(prompt)
	? insert()
	: extract_max();
  }
  return output;
}

