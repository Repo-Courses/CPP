#include <memory>
#include <iostream>
#include <limits>

//Implement a generic function that takes a single argument of any type and returns the type in string format.
template<typename T>
std::string Foo(T const& arg) {
    return std::string(typeid(arg).name());
}

template <typename T>
T maxValue() {
    // default implementation
    return T();
}

template <>
int maxValue<int>() {
    return std::numeric_limits<int>::max();
}

template <>
long maxValue<long>() {
    return std::numeric_limits<long>::max();
}

int main() {
    int max_int = maxValue<int>();
    std::cout << "Maximum value of int: " << max_int << std::endl;

    long max_long = maxValue<long>();
    std::cout << "Maximum value of long: " << max_long << std::endl;
}
