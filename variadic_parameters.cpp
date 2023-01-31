#include <iostream>

//  value can be evaluated at compile-time thanks to constexpr.
constexpr int factorial_compiletime(int n)
{
    if(n <= 1)
        return 1;
    return n*factorial_compiletime(n-1);
}

template<int n>
struct Factorial {
    static const int value = n * Factorial<n-1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

template<>
struct Factorial<1> {
    static const int value = 1;
};

// Inline function i run-time da calistirabilir compiler time da, bu tamamen onun performans analiz terchini,  inline function can be evaluated either at compile-time or runtime, but the compiler may choose not to inline the function if it determines that inlining would produce larger or slower code.
inline int add(int a, int b)
{
    return a + b;
}

// variadic parameters: parameter packs and pack expansions

template<int a, int b> struct Div       { static const int value = a/b; };
template<int k       > struct Div<k, 0> { static const int value = k; };

template<int a, int b> struct Mul { static const int value = a*b; };


/*
// fold expression
template<int ... As> struct Multiply { static const int value = (As * ...);
};
 */

template<int first, int ... rest>
struct Multiply {
    static const int value = (first * ... * rest);
};

// variadic parameters: parameter packs and pack expansions
template<typename T>
inline void PRINT(const T& t)
{
    std::cout << "'" << t << "'";
}

template<typename ... Ts>
inline void print(const Ts& ... ts)
{
    (PRINT(ts), ...);
}

int main() {
    std::cout << "The factorial of 5 is: " << Factorial<5>::value << std::endl;
    std::cout << "Multiply Result: " << Multiply<5, 10, 2>::value << std::endl;

    print<int, const char*, double, float>(5, "Hello", 5.3, 3.14f);
    print(5, "Hello", 5.3, 3.14f);
    return 0;
}
