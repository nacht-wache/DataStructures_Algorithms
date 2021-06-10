#include <member_functions.h>

SinglyLinkedList::SinglyLinkedList(const std::initializer_list<int>& lst) {
  try {
	for (auto value : lst) {
	  Node* new_node = new Node;
	  new_node->key = value;
	  new_node->prev = head;
	  head = new_node;
	}
  } catch (std::bad_alloc& e) {
	std::cerr << "Can't allocate memory for the new Node of an initializer_list\n";
	throw;
  }
}

SinglyLinkedList::~SinglyLinkedList() {
  if (!empty()) {
	while (head->prev != nullptr) {
	  Node* temp = head->prev;
	  delete head;
	  head = temp;
	}
  }
  delete head;
}

