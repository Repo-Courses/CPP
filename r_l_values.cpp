#include <iostream>

// l-value refers to a memory location and has a value that persists beyond a single expression.
int x = 42; // x is an l-value expression
int y = x; // y is also an l-value expression

// r-value represents a temporary value that does not persist beyond the expression in which it appears.
int z = 42 + 23; // 42 + 23 is an r-value expression

int main()
{
    std::cout << "x: " << x << std::endl; // x is an l-value, it has a value that persists
    std::cout << "y: " << y << std::endl; // y is an l-value, it has a value that persists

    // z is an r-value, it's a temporary value that only exists in this expression
    std::cout << "z: " << z << std::endl;

    // This line is invalid because we can't modify an r-value
    //z = 100; // Error: r-value cannot be modified

    return 0;
}

/*
In C++11 and later, the distinction between l-values and r-values is further refined with the introduction of l-value references and r-value references.
An l-value reference is a reference that refers to an l-value, and an r-value reference is a reference that refers to an r-value. 
These new types allow for better control over the lifetime and behavior of temporary objects in C++, leading to more efficient and expressive code.
*/
