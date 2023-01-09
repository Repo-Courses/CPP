#include <iostream>


/*
Create a class called "SmartPointer" that wraps a raw pointer and
 automatically deletes the memory when the SmartPointer object goes out of scope.
 The class should overload the following operators:
"T& operator*()" for dereferencing the wrapped pointer
"T* operator->()" for accessing members of the pointed-to object
"operator bool()" for checking if the wrapped pointer is null

*/
template <typename T>
class SmartPointer {
public:
    explicit SmartPointer(T* ptr) : ptr_(ptr) {};
    ~SmartPointer() {delete ptr_;}

    T& operator*() { return *ptr_; }
    T operator->() { return ptr_; }
    operator bool() { return ptr_ != nullptr; }

private:
    T* ptr_;
};

int main() {
    SmartPointer<int> smart_ptr(new int(10));
    std::cout << *smart_ptr << std::endl; // prints 10
    *smart_ptr = 20;
    std::cout << *smart_ptr << std::endl; // prints 20
    }
