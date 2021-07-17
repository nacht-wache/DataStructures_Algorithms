#ifndef DS_LIST_LL_U_LL_U_H
#define DS_LIST_LL_U_LL_U_H

#include <iostream>

class SinglyLinkedList {
 private:

  struct Node {
	Node* prev = nullptr;
	int key = 0;

	Node() = delete;
	explicit Node(int key, Node* prev = nullptr)
		: prev(prev), key(key) {}
	~Node() = default;
  };

  Node* head = nullptr;

 public:
  SinglyLinkedList() = default;
  SinglyLinkedList(const std::initializer_list<int>& lst);
  SinglyLinkedList(const SinglyLinkedList& list);
  ~SinglyLinkedList();
  void insert(int value);

  void del_val(int value);
  void del_ptr(Node* node);
  Node* find(int key);
  bool empty();
};

#endif//DS_LIST_LL_U_LL_U_H
