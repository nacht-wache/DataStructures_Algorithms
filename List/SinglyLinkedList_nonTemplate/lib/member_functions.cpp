#include "SinglyLinkedList.h"

void SinglyLinkedList::insert(int key) {
  try {
	Node* new_node = new Node;
	new_node->prev = head;
	new_node->key = key;
	head = new_node;
  } catch (std::bad_alloc& e) {
	std::cerr << e.what() << ' ' << "Some issues on insertion\n";
  }
}

/*Node* SinglyLinkedList::find(int key) {
  if (empty()) {
	return nullptr;
  }
  Node* ptr = head;
  while (ptr->key != key && ptr->prev != nullptr) {
	ptr = ptr->prev;
  }
  if (ptr->key != key) {
	return nullptr;
  }
  return ptr;
}*/

void SinglyLinkedList::del_val(int key) {
  if (empty()) {
	return;
  }

  Node* ptr = head;
  if (head->prev != nullptr && head->key == key) {//delete head-key
	head = head->prev;
	delete ptr;
	return;
  }

  while (ptr->prev != nullptr && ptr->prev->key != key) {	// find pointer to next Node
	ptr = ptr->prev;                                     	// after the Node with a key
  }
  if (ptr->prev != nullptr && ptr->prev->key == key) {		// standard search
	Node* temp = ptr->prev->prev;                     		// shirt-circuit evaluation used
	delete ptr->prev;
	ptr->prev = temp;
  } else if (head->key == key) {// single-Node list
	delete head;
	head = nullptr;
  }
}

void SinglyLinkedList::del_ptr(Node* node) {
  if (node == nullptr) {
	throw std::runtime_error("UB: argument with 'nullptr' key in the del_ptr function");
  }
  Node* ptr = head;
  if (head->prev != nullptr && head == node) {//delete head-key
	head = head->prev;
	delete ptr;
	return;
  }

  while (ptr->prev != nullptr && ptr->prev != node) {
	ptr = ptr->prev;
  }
  if (ptr->prev == node) {
	ptr->prev = node->prev;
	delete node;
  }
}

bool SinglyLinkedList::empty() {
  if (head == nullptr) {
	return true;
  }
  return false;
}