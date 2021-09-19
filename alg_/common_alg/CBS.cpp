#include <iostream>
#include <stack>
#include <string>

enum bracket_type {
  open_brace = '{',
  close_brace = '}',
  open_round = '(',
  close_round = ')',
  open_quadro = '[',
  close_quadro = ']'
};

class Solution {
  std::stack<char> brackets;
  std::stack<std::string::const_iterator> indexes;

 public:
  int solve(const std::string &s) {

	for (auto it{s.cbegin()}; it != s.cend(); ++it) {
	  if (is_open_bracket(*it)) {
		brackets.push(*it);
		indexes.push(it);
	  } else if (is_close_bracket(*it)) {
		if (brackets.empty())
		  return static_cast<int>(std::distance(s.cbegin(), it) + 1);

		if (check_stack(*it)) {
		  brackets.pop();
		  indexes.pop();
		} else {
		  return static_cast<int>(std::distance(s.cbegin(), it) + 1);
		}
	  }
	}

	if (!indexes.empty())
	  return static_cast<int>(std::distance(s.cbegin(), indexes.top()) + 1);
	std::cout << "Success\n";
	return 0;
  }

  static bool is_open_bracket(char ch) {
	return ch == open_brace || ch == open_quadro || ch == open_round;
  }

  static bool is_close_bracket(char ch) {
	return ch == close_brace || ch == close_quadro || ch == close_round;
  }

  bool check_stack(char ch) {
	switch (ch) {
	  case close_brace:
		return brackets.top() == open_brace;
	  case close_round:
		return brackets.top() == open_round;
	  case close_quadro:
		return brackets.top() == open_quadro;
	  default:
		return false;
	}
  }
};