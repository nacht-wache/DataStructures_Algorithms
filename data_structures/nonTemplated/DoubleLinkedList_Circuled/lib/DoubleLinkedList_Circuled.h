#ifndef DS_LIST_DOUBLELINKEDLIST_CIRCULED_LIB_DOUBLELINKEDLIST_CIRCULED_H_
#define DS_LIST_DOUBLELINKEDLIST_CIRCULED_LIB_DOUBLELINKEDLIST_CIRCULED_H_

#include <string>

class List {
 private:

  struct Node {
	Node *prev = nullptr;
	Node *next = nullptr;
	std::string value;

	explicit Node(const std::string &value, Node *prev = nullptr, Node *next = nullptr)
		: prev(prev), next(next), value(value) {}
  };

  Node *head = nullptr;
  Node *tail = nullptr;
  size_t sz = 0;

 public:
  List() = default;
  List(const std::initializer_list<std::string> &lst);
  ~List();

  // Element access
  std::string &front();
  std::string &back();

  // Capacity
  bool empty() const;
  [[nodiscard]] size_t size() const;
  [[nodiscard]] size_t max_size() const;

  // Modifiers
  void clear();
  void insert(const std::string &s);
  void erase(const std::string &s);
  void push_front(const std::string &s);
  void pop_front(const std::string &s);
  void push_back(const std::string &s);
  void pop_back(const std::string &s);
  void resize(size_t);
  void swap();

};

#endif //DS_LIST_DOUBLELINKEDLIST_CIRCULED_LIB_DOUBLELINKEDLIST_CIRCULED_H_
