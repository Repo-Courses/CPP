#include <iostream>

// Callable structs that define the operator() with return type 'auto'
struct Callable1 {
  // auto operator() - this function operator returns auto type,
  // which will be determined based on the argument passed to it
  auto operator() (int) const {
    // when int argument is passed to this operator, it returns void and prints "int"
    std::cout << "int\n";
  }
};

struct Callable2 {
  auto operator() (float) const {
    // when float argument is passed to this operator, it returns void and prints "float"
    std::cout << "float\n";
  }
};

struct Callable3 {
  auto operator() (double) const {
    // when double argument is passed to this operator, it returns void and prints "double"
    std::cout << "double\n";
  }
};

int main() {
  // object of Callable1
  Callable1 callable1;
  // calling operator() of Callable1 with int argument
  callable1(10);  // prints "int"

  // object of Callable2
  Callable2 callable2;
  // calling operator() of Callable2 with float argument
  callable2(10.0f);  // prints "float"

  // object of Callable3
  Callable3 callable3;
  // calling operator() of Callable3 with double argument
  callable3(10.0);  // prints "double"

  return 0;
}
