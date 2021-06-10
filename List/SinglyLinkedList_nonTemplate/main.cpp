#include <SinglyLinkedList.h>
#include <iostream>

int main() {
  SinglyLinkedList list;
  for (int i = 0; i < 1000; ++i) {
	list.insert(i);
  }

  Node* del = list.find(999);
  list.del_ptr(del);
  int find = 0;
  if (list.find(find) != nullptr) {
	std::cout << list.find(find) << ' ' << list.find(find)->key;
  }
}
