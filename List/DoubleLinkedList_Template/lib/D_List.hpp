#ifndef DS_LIST_DOUBLELINKEDLIST_TEMPLATE_LIB_D_LIST_HPP_
#define DS_LIST_DOUBLELINKEDLIST_TEMPLATE_LIB_D_LIST_HPP_

template <typename T>
class D_List {
 private:
  template <bool IsConst>
  class common_iter;
  struct Node {
	T value;
	Node* prev {nullptr};
	Node* next {nullptr};

	Node() = delete;
	explicit Node(T value, Node* prev = nullptr, Node* next = nullptr) noexcept
		: value(std::move_if_noexcept(value)), prev(prev), next(next) {};
	Node(const Node& node) = default;
	~Node() = default;
  };

  Node* head {nullptr};
  Node* tail {nullptr};
  size_t sz = 0;

 public:
  D_List() = default;
  D_List(const std::initializer_list<T>& lst);
  ~D_List();

  bool empty();
  size_t size() const {
	return sz;
  }

 private:
  template <bool IsConst>
 class common_iter : public std::iterator_traits<common_iter<IsConst>> {
   public:
   typedef T value_type;
   typedef std::ptrdiff_t difference_type;
   typedef Node* pointer;
   typedef const Node* const_pointer;
   typedef T& reference;
   typedef const T& const_reference;
   typedef std::bidirectional_iterator_tag iterator_category;

   private:
	using ConditionalPtr = std::conditional_t<IsConst, const Node*, Node*>;
	using ConditionalReference = std::conditional_t<IsConst, const_reference , reference>;
	using ConditionalIter = std::conditional_t<IsConst, const common_iter&, common_iter>;

	ConditionalPtr ptr;

   public:
    explicit common_iter(Node* node) : ptr(node) {};
    common_iter(const common_iter<IsConst>& iter) = default;
    ~common_iter() = default;

    common_iter& operator=(const common_iter<IsConst>& iter) {
      ptr = iter.ptr;
    }

	ConditionalReference operator*() {
	  return ptr->value;
	}
	ConditionalPtr operator->() {
	  return ptr;
	}
	/*template <typename U>
	std::conditional_t<IsConst, const U&, U&> operator->*(U T::*p) {
	  return (*ptr).*p;
	}*/

	common_iter& operator++() {
	  ptr = ptr->next;
	  return *this;
	}

	common_iter operator++(int) const {
	  common_iter iter(ptr->next);
	  return iter;
	}

	common_iter operator--(int) const {
	  common_iter iter(ptr->prev);
	  return iter;
	}

	common_iter& operator--() {
	  ptr = ptr->prev;
	  return *this;
	}

   bool operator!=(const common_iter& iter) const {
	  return ptr != iter.ptr;
	}

  };

 public:
  using iterator = common_iter<false>;
  using const_iterator = common_iter<true>;

  iterator begin() {
    iterator it(tail);
	return it;
  }

  iterator end() {
    iterator it(head);
	return it;
  }
};

template <typename T>
D_List<T>::D_List(const std::initializer_list<T>& lst) {
  if (lst.size() == 0) { return; }

  for (auto item : lst) {
	if (empty()) {
	  head = new Node(item);
	  tail = head;
	  ++sz;
	} else if (sz == 1) {
	  Node* node = new Node(item, tail, tail);
	  head->next = node;
	  head = node;
	  tail->next = head;
	  tail->prev = head;
	  ++sz;
	} else {
	  Node* node = new Node(item, head, tail);
	  head->next = node;
	  head = node;
	  tail->prev = head;
	  ++sz;
	}
  }
}

template <typename T>
D_List<T>::~D_List() {
  if (empty()) { return; }

  while (head != tail) {
	Node* temp {head->prev};
	delete head;
	head = temp;
  }
  delete head;
}

template <typename T>
bool D_List<T>::empty() {
  return sz == 0;
}

#endif //DS_LIST_DOUBLELINKEDLIST_TEMPLATE_LIB_D_LIST_HPP_
