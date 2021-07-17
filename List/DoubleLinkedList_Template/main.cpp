#include <iostream>
#include <stack>
#include <D_List.hpp>
#include <list>
#include <iterator>

int main() {
  D_List<int> lst {1, 2, 3, 4, 5, 6};
  for(D_List<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it;
  }
}
