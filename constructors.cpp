#include <iostream>

class MyClass {
 public:
  MyClass() : data_(new int[10]) {
    std::cout << "Default constructor called" << std::endl;
  }

  MyClass(const MyClass& other) : data_(new int[10]) {
    std::cout << "Copy constructor called" << std::endl;
    std::copy(other.data_, other.data_ + 10, data_);
  }

  MyClass(MyClass&& other) : data_(other.data_) {
    std::cout << "Move constructor called" << std::endl;
    other.data_ = nullptr;
  }

  MyClass& operator=(const MyClass& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    std::copy(other.data_, other.data_ + 10, data_);
    return *this;
  }

  MyClass& operator=(MyClass&& other) {
    std::cout << "Move assignment operator called" << std::endl;
    data_ = other.data_;
    other.data_ = nullptr;
    return *this;
  }

  ~MyClass() {
    std::cout << "Destructor called" << std::endl;
    delete[] data_;
  }

 private:
  int* data_;
};

MyClass createMyClass() {
  return MyClass();
}

int main() {
  // Move constructor is called here
  // because createMyClass() returns a temporary object
  // that can be moved into the variable temp
  MyClass temp = createMyClass();

  // Move assignment operator is called here
  // because temp is an existing object that can be moved
  // into the variable temp2
  MyClass temp2 = std::move(temp);

  // Copy constructor is called here
  // because temp2 is an existing object that needs to be copied
  // into the variable temp3
  MyClass temp3 = temp2;

  // Copy assignment operator is called here
  // because temp3 is an existing object that needs to be assigned
  // the value of temp2
  temp3 = temp2;

  return 0;
}

/*
Default constructor called
Move constructor called
Move constructor called
Copy constructor called
Copy assignment operator called
Destructor called
Destructor called
Destructor called
*/
