#include <SinglyLinkedList.h>
#include <iostream>

int main() {
  SinglyLinkedList list;
  for (int i = 0; i < 1000; ++i) {
	list.insert(i);
  }

  list.del_val(30);
  //std::cout << list.find(30); 							// UB: nullptr
  SinglyLinkedList list_2 = {1, 2, 3, 4};
  list_2.del_ptr(list_2.find(3));
  //std::cout << list_2.find(3);							// UB: nullptr
}
