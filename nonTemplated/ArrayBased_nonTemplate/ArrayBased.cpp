#include "ArrayBased.h"

ArrayBased::ArrayBased(size_t n) : sz(n) {
  if (n == 0) { return; }

  top = new std::string[n];
}

ArrayBased::~ArrayBased() {
  if (empty()) { return; }

  for (size_t i = 0; i < top_pos; ++i) {
	(top + top_pos)->~basic_string();
  }
  delete[] (top);
}
void ArrayBased::push(std::string x) {
  if (top_pos == sz) {
	std::cerr << "Overflow\n";
	return;
  }
  top[top_pos] = x;
  ++top_pos;
}

bool ArrayBased::empty() {
  if (sz == 0) { return true; }
  return false;
}

