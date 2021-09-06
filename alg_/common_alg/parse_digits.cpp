#include <iostream>
#include <string>

class TextInput {
 public:
  virtual void add(char c) { s += c; }

  std::string getValue() { return s; }

 protected:
  std::string s;
};

class NumericInput : public TextInput {
 public:
  void add (char c) override {
    if(isdigit(c))
      s += c;
  }
};
