#ifndef DS_STACK_STACK_H
#define DS_STACK_STACK_H

#include <initializer_list>
#include <iostream>

template<typename T>
struct Node {
  Node<T>* prev = nullptr;
  T key;
};

template<typename T>
class ListBased_T {
 private:
  Node<T>* top = nullptr;

 public:
  ListBased_T() = default;
  ~ListBased_T();
  ListBased_T<T>(const std::initializer_list<T>& lst);

  ListBased_T(const ListBased_T<T>& value) = delete;
  ListBased_T<T>& operator=(const ListBased_T<T>& value) = delete;

  T pop();
  void push(const T& value);
  bool empty();
};

template<typename T>
ListBased_T<T>::ListBased_T(const std::initializer_list<T>& lst) {
  Node<T>* ptr;
  for (typename std::initializer_list<T>::iterator it = lst.begin(); it != lst.end(); ++it) {
	try {
	  ptr = new Node<T>;
	  ptr->key = *it;
	  ptr->prev = top;
	} catch (...) {
	  delete ptr;
	  throw;
	}
	top = ptr;
  }
}

template<typename T>
T ListBased_T<T>::pop() {
  if (empty()) {
	throw std::out_of_range("Underflow");
  }
  Node<T>* ptr = top;
  if (ptr->prev != nullptr) {
    T key = top->key;
    top = top->prev;
    delete ptr;
	return key;
  } else {
    T key = top->key;
    delete top;
    top = nullptr;
	return key;
  }
}

template<typename T>
void ListBased_T<T>::push(const T& value) {
  Node<T>* ptr;
  try {
	ptr = new Node<T>;
	ptr->prev = top;
	ptr->key = value;
  } catch (...) {
	delete ptr;
	throw;
  }
  top = ptr;
}

template<typename T>
ListBased_T<T>::~ListBased_T() {
  if (empty()) {
	return;
  }
  Node<T>* ptr = top;
  while (ptr->prev != nullptr) {
	ptr = ptr->prev;
	delete top;
	top = ptr;
  }
  delete top;
}

template<typename T>
bool ListBased_T<T>::empty() {
  if (top == nullptr) {
	return true;
  }
  return false;
}

#endif//DS_STACK_STACK_H
