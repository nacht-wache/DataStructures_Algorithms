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
class ListBased {
 private:
  Node<T>* top = nullptr;

 public:
  ListBased() = default;
  ~ListBased();
  ListBased<T>(const std::initializer_list<T>& lst);

  ListBased(const ListBased<T>& value) = delete;
  ListBased<T>& operator=(const ListBased<T>& value) = delete;

  T pop();
  void push(const T& value);
  bool empty();
};

template<typename T>
ListBased<T>::ListBased(const std::initializer_list<T>& lst) {
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
T ListBased<T>::pop() {
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
void ListBased<T>::push(const T& value) {
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
ListBased<T>::~ListBased() {
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
bool ListBased<T>::empty() {
  if (top == nullptr) {
	return true;
  }
  return false;
}

#endif//DS_STACK_STACK_H
