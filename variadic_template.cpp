#include <numeric>
#include <string>
#include <iostream>
#include <vector>


//Given a template T with a non-type parameter pack, write a function that counts the number of elements in the pack.

template <typename... T>
int countElement(const T&... args) {
    return sizeof...(args);
}

template <typename... T>
void print(const T&... args) {
    (std::cout << ... << args) << '\n';
}

// Write a variadic template function that takes an arbitrary number of arguments and returns the product of all the arguments.
template <typename... Args>
auto totalProduct(const Args&... args) {
    return (args * ...);
}


// Given a function parameter pack, write a recursive function that returns the sum of all elements in the pack.
template <typename... Args>
auto totalSum(const Args&... args) {
    return (args + ...);
}

// Given a parameter pack, write a function that returns the maximum element in the pack using fold expressions.
template <typename... T>
constexpr auto max_element(T... args) {
    return (args > ...);
}

// Given a constant expression, write a constexpr function that calculates the factorial of a given number.
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}


int main() {
    //std::cout << reduceSum<int>(1, 2, 3, 4); // returns 10;
    print(1, 2, 3, "a");  // prints "123\n"
    print(totalSum(3,2,4,54,6));
    print(totalProduct(3,2,4,54,6));
    std::cout << max_element(23,3,23,23,23,43);
}
