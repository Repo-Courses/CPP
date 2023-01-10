#include <iostream>
#include <vector>

/*
Implement a class SmartString that manages a dynamically allocated char array, and implements a move constructor and a move assignment operator,
while ensuring that the ownership of the memory is transferred correctly and no memory leaks occur.
*/
class SmartString {
public:
    std::vector<char> vec;

    SmartString() = default;
    SmartString(const char* str) : vec(str, str + strlen(str)) {} //
    
    SmartString(const SmartString& other) : vec(other.vec) {}  // copy constructor

    SmartString(SmartString&& other) : vec(std::move(other.vec)) {}; //Move constructor.

    SmartString& operator=(const SmartString& other) {
        vec = other.vec;
        return *this;
    }

    SmartString& operator=(SmartString&& other) {
        vec = std::move(other.vec);
        return *this;
    }
};


int main() {
    SmartString s1;
    SmartString s2 = "Hello, World!";
    s1 = s2; //copy assignment operator
    std::cout << "s1: " << &s1.vec[0] << std::endl;
    std::cout << "s2: " << &s2.vec[0] << std::endl;
    SmartString s3 = std::move(s1);
    std::cout << "s3: " << &s3.vec[0] << std::endl;
    std::cout << "s1: " << &s1.vec[0] << std::endl;
    return 0;
}
