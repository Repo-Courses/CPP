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

template <typename T, typename... Args>
T minValue(T first, Args... args) {
    T min = first;
    ((min = std::min(min, args)), ...);
    return min;
}

template <typename T, typename... Args>
T maxValue(const T& first, Args... args) {
    T max = first;
    ((max = std::max(max, args)), ...);
    return max;
}

template <typename... T>
void print(const T&... args) {
    (std::cout << ... << args) << '\n';
}

template <typename... F>
void callFunctions(F... f) {
    (f(), ...);
}

void func1() { std::cout << "Function 1 called." << std::endl; }
void func2() { std::cout << "Function 2 called." << std::endl; }

// Write a variadic template function that takes an arbitrary number of arguments and returns the number of occurrences of a specific element in the arguments. ??

template<typename... Args>
std::tuple<Args...> make_tuple(Args... args) {
    return std::tuple<Args...>(args...);
}


int main() {
    //std::cout << reduceSum<int>(1, 2, 3, 4); // returns 10;
    print(1, 2, 3, "a");  // prints "123\n"
    print(totalSum(3,2,4,54,6));
    print(totalProduct(3,2,4,54,6));
    std::cout << max_element(23,3,23,23,23,43);
    std::cout << minValue(5.5, 7.7, 3.3, 2.2) << std::endl; //2.2
    std::cout << maxValue(5.5, 7.7, 3.3, 2.2) << std::endl; //7.7
    std::cout << minValue('a', 'b', 'c', 'd') << std::endl; //a
    callFunctions(func1, func2);
    auto tuple = make_tuple(1, "hello", 3.14);
    std::cout << std::get<0>(tuple) << " " << std::get<1>(tuple) << " " << std::get<2>(tuple) << std::endl;
}
