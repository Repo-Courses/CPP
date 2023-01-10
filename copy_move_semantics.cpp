#include <iostream>

/*
Explain the RAII principle and how it relates to resource management in C++.
Provide an example of how you would use RAII to manage the lifetime of a dynamically allocated object.

 Answer:
 RAII used in C++ to manage the lifetime of resources, such as dynamically allocated memory, file handles, and network sockets.
 The basic idea behind RAII is that a resource is acquired when an object is constructed, and it is automatically released when the object is destroyed.

Describe the difference between copy semantics and move semantics in C++.
Give an example of a scenario where it would be beneficial to use move semantics instead of copy semantics.

 Answer:
 Copy semantics refer to the traditional way of copying objects in C++, which involves creating a new object and initializing it with the data of the original object.
 This is done using the copy constructor and the assignment operator. When an object is copied, a new object is created and the data of the original object is copied over to the new object.

 Move semantics, on the other hand, is an optimization that is used to avoid unnecessary copies of objects.
 Instead of creating a new object and copying the data, a move operation transfers the ownership of the data to a new object. The original object is left in a "moved-from" state, which means that it is still valid but should not be used anymore.

Default copy constructor:
This is a constructor with no arguments that the compiler will generate for a class if no copy constructor is defined.

class Example {
public:
    int x;
    Example() = default; // this generates a default copy constructor
};

Copy constructor with shallow copy: This copy constructor creates a new object and copies only the pointers or references to the data of the original object, rather than copying the actual data.
This can be useful when dealing with large or expensive-to-copy objects.
class Example {
public:
    std::unique_ptr<int[]> data;
    Example(const Example& other) : data(other.data) {}
};

Copy constructor with deep copy: This copy constructor creates a new object and copies all of the data, including the contents of any pointers or references, from the original object to the new object.
class Example {
public:
    std::unique_ptr<int[]> data;
    Example(const Example& other) : data(std::make_unique<int[]>(*other.data)) {}
};

::move bir objeyi tamamen baska bir objeye transfer ediyorsun. Bastaki obje gunun sonunda nullpointer olabiliyor, diger objede bastaki objenin sahip oldugu her seye sahip oluyor.

class Example {
public:
    std::unique_ptr<int[]> data;
    Example& operator=(Example&& other) {
        data = std::move(other.data);
        return *this;
    }
};



*/
class Example {
public:
    std::unique_ptr<int[]> data;
    Example& operator=(Example&& other) {
        data = std::move(other.data);
        return *this;
    }
};

int main() {
    Example ex1, ex2;
// fill ex2 with data
    ex1 = std::move(ex2); // move assignment operator is called here
    
    }
