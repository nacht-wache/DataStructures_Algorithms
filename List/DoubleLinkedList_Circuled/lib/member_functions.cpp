#include <DoubleLinkedList_Circuled.h>

bool List::empty() const {
  return sz == 0;
}

std::string& List::front() {
  return head->value;
}

std::string& List::back() {
  return tail->value;
}

size_t List::size() const{
  return sz;
}

size_t List::max_size() const {
  //return std::numeric_limits<std::string>::max(); ??
}

void List::clear() {
  //  this->~List(); -- you don't want to call destructor in clear()
  //  need to implement private substructure iterator first
  //  to call erase(list.begin(), list.end());
}

void List::insert(const std::string& s) {
  // iterator first
}

void List::erase(const std::string& s) {
  // iterator first
}

