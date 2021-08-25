#ifndef DS_STACK_ARRAYBASED_NONTEMPLATE_ARRAY_BASED_H_
#define DS_STACK_ARRAYBASED_NONTEMPLATE_ARRAY_BASED_H_

#include <iostream>

class ArrayBased {
 private:
  std::string *top = nullptr;
  size_t sz = 0;
  size_t top_pos = 0;

 public:
  ArrayBased() = default;
  explicit ArrayBased(size_t n);
  ~ArrayBased();

  void push(std::string x);
  bool empty();
};

#endif //DS_STACK_ARRAYBASED_NONTEMPLATE_ARRAY_BASED_H_
