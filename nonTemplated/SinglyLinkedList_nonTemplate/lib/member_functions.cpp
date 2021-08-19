#include "SinglyLinkedList.h"

void SinglyLinkedList::insert(int key) {
  Node *new_node = new Node(key, head);
  head = new_node;
}

/*Node* SinglyLinkedList::find(int key) {                            // should be rewritten
  if (empty()) {                                                	// it's a mistake to return a Node*
	return nullptr;                                                // Node should be private
  }																  // It should return iterator :/
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

  Node *ptr = head;
  if (head->prev != nullptr && head->key == key) { //delete head-key
	head = head->prev;
	delete ptr;
	return;
  }

  while (ptr->prev != nullptr && ptr->prev->key != key) {    // find a ptr to a Node with a ptr
	ptr = ptr->prev;                                        // to the Node with the key
  }
  if (ptr->prev != nullptr && ptr->prev->key == key) {        // standard search
	Node *temp = ptr->prev->prev;                            // shirt-circuit evaluation used
	delete ptr->prev;
	ptr->prev = temp;
  } else if (head->key == key) {                            // single-Node list
	delete head;
	head = nullptr;
  }
}

void SinglyLinkedList::del_ptr(Node *node) {
  if (node == nullptr) {
	throw std::runtime_error("UB: argument with 'nullptr' key in the del_ptr function");
  }
  Node *ptr = head;
  if (head->prev != nullptr && head == node) {                // delete head-key
	head = head->prev;
	delete ptr;
	return;
  }

  while (ptr->prev != nullptr && ptr->prev != node) {        // same as for del_val
	ptr = ptr->prev;
  }
  if (ptr->prev == node) {
	ptr->prev = node->prev;
	delete node;
  }
}

bool SinglyLinkedList::empty() {                            //helper function
  if (head == nullptr) {
	return true;
  }
  return false;
}