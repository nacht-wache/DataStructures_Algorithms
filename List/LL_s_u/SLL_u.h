#ifndef DS_LIST_LL_U_LL_U_H
#define DS_LIST_LL_U_LL_U_H

#include <iostream>

struct Node {
  Node *prev = nullptr;
  int key = 0;

  Node() = default;
  ~Node() = default;
};

class SLL_u {
private:
  Node *head = nullptr;

public:
  SLL_u() = default;
  SLL_u(const SLL_u &list);
  ~SLL_u();
  void insert(int value);

  void del_val(int value);
  void del_ptr(Node *node);
  Node *find(int key);
  bool empty();
};

#endif//DS_LIST_LL_U_LL_U_H
