#include <iostream>

class Example {
public:
    Example(int x) : x_(x) {}

    // This function returns the value of x_, but can also modify it, even if the object is const
    int getX() const {
        // The value of x_ can be modified even though the function is declared const
        x_++; // This is allowed because x_ is declared mutable
        return x_;
    }

private:
    // Declaring x_ as mutable allows it to be modified even if the object is const
    mutable int x_;
};

int main() {
    // Create a const object of Example
    const Example example(10);

    // Call getX() on the const object, which returns the value of x_
    std::cout << example.getX() << std::endl; // Prints 11
    std::cout << example.getX() << std::endl; // Prints 12

    return 0;
}

/* 
In C++, the mutable keyword is used to declare class data members that can be modified even if the containing object is constant.
When a data member is declared as mutable, its value can be changed even if the object is declared as const. This allows the data member to be updated even if the rest of the object's state is constant. 
The mutable keyword can only be used in class member function declarations, not in local or global variables or function parameters.
*/
