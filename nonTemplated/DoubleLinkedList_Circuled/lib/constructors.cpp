#include "DoubleLinkedList_Circuled.h"

List::List(const std::initializer_list<std::string> &lst) {
  if (std::empty(lst)) { return; }

  for (const auto &value : lst) {
	if (empty()) {
	  head = new Node(value);
	  tail = head;
	  ++sz;
	} else if (head == tail) {
	  Node *node = new Node(value, tail, tail);
	  tail->next = node;
	  tail->prev = node;
	  head = node;
	  ++sz;
	} else {
	  Node *node = new Node(value, head, tail);
	  head = node;
	  tail->prev = head;
	  ++sz;
	}
  }
}

List::~List() {
  if (empty()) { return; }
  while (head != tail) {
	Node *node = head->prev;
	delete head;
	head = node;
  }
  delete head;
  sz = 0;
}