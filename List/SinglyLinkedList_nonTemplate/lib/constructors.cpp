#include <SinglyLinkedList.h>

SinglyLinkedList::SinglyLinkedList(const std::initializer_list<int>& lst) {
  Node* new_node;
  try {
	for (auto value : lst) {
	  new_node = new Node;
	  new_node->key = value;
	  new_node->prev = head;
	  head = new_node;
	}
  } catch (std::bad_alloc& e) {
	std::cerr << "Can't allocate memory for the new Node of an initializer_list\n";
	delete new_node;
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

