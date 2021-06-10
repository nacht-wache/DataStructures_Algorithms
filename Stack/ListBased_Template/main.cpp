#include <ListBased.h>

int main() {
  try {
	ListBased<int> s = {1, 2};
	std::cout << s.pop() << ' ';
	std::cout << s.pop() << ' ';
	s.push(1);
	std::cout << s.pop() << ' ';

	ListBased<std::string> string_stack = {"abc", "aaa", "aka"};
	std::cout << string_stack.pop() << ' ';
	std::cout << string_stack.pop() << ' ';
	string_stack.push("abc");
	std::cout << string_stack.pop() << ' ';
  } catch (const std::exception& e) {
	std::cerr << e.what() << '\n';
  }
}