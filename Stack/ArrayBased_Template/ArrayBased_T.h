#ifndef DS_STACK_ARRAYBASED_TEMPLATE_ARRAYBASED_T_H_
#define DS_STACK_ARRAYBASED_TEMPLATE_ARRAYBASED_T_H_

// don't use reinterpret_cast to create a dynamic array in prod, pls :D

template<typename T>
class ArrayBased_T {
 private:
  T* arr = nullptr;
  size_t sz = 0;
  size_t top_pos = 0;

 public:
  explicit ArrayBased_T(size_t sz);
  ~ArrayBased_T<T>();

  void push(const T& value);
};

template<typename T>
ArrayBased_T<T>::ArrayBased_T(size_t sz): sz(sz) {
  if (sz == 0) {
	return;
  }
  try {
	arr = reinterpret_cast<T*>(new char[sz * sizeof(T)]);		// correct allocation
  } catch (...) {
	delete[] reinterpret_cast<char*>(arr);					// correct deletion
	arr = nullptr;
	throw;
  }
}

template<typename T>
ArrayBased_T<T>::~ArrayBased_T<T>() {
  if (sz == 0) {
	return;
  }

  for (size_t i = 0; i < top_pos; ++i) {						// correct manual destructors call
	(arr + top_pos) -> T::~T();
  }
  delete[] reinterpret_cast<char*>(arr);						// correct deletion
  arr = nullptr;
}

template<typename T>
void ArrayBased_T<T>::push(const T& value) {
  if (top_pos == sz) {
	std::cerr << "Overflow\n";
	return;
  }
  new (arr + top_pos) T(value);									// correct initialization
  ++top_pos;
}

#endif //DS_STACK_ARRAYBASED_TEMPLATE_ARRAYBASED_T_H_
