#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

//Create a function that takes a string and a character as input, and uses lambdas, overloads, and error handling to find and return the number of occurrences of the character in the string.
int Foo_str(const std::string& str, char ch) {
    // This is the easiest way.
    // auto numOfOccurance = std::count(str.begin(), str.end(), ch);

    if (str.empty()) {
        std::cout << "Error: input string is empty" << std::endl;
        return -1;
    }
    int numOfOccurrences = std::count_if(str.begin(), str.end(), [&](char c){ return c == ch; });
    return numOfOccurrences;
}

//Write a function that takes in a vector of integers and returns the smallest element.
int Foo(const std::vector<int>& vec) {
   int smallest = *std::min_element(vec.begin(), vec.end());
   return smallest;
}

//Write a function that takes in a string and returns a boolean indicating whether the string is a palindrome or not.
bool Foo2(std::string str){
    std::string str_reverse = str;
    std::reverse(str_reverse.begin(), str_reverse.end());
    return str_reverse == str;
}

//Write a function that takes in a list of strings and a string and returns a boolean indicating whether the string is in the list.
auto Foo3(const std::vector<std::string>& str_list, const std::string& str) {
    return std::find(str_list.begin(), str_list.end(), str) != str_list.end();
}

//Write a function that takes in a vector of integers and returns a vector containing the elements of the original vector in sorted order.
std::vector<int> Foo4(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    return vec;
}

//Write a function that takes in a vector of strings and returns a vector containing the strings sorted in lexicographic order.
std::vector<std::string> Foo5(std::vector<std::string>& str_list) {
    std::sort(str_list.begin(), str_list.end());
    return str_list;
}

//Write a function that takes in a vector of integers and returns the number of elements that are multiples of 3.
std::vector<int> Foo6(const std::vector<int>& v) {
    std::vector<int> result;
    std::copy_if(v.begin(), v.end(), std::back_inserter(result), [](int x) { return x % 3 == 0; });
    return result;
}

// Write a function that takes in a vector of integers and returns the second largest element.
int Foo7(const std::vector<int>& vec) {
    std::set<int> unique_elements(vec.begin(), vec.end());
    return *std::prev(unique_elements.end());
}

//Write a function that takes in a vector of integers and two integers a and b, and returns the number of elements in the vector that are strictly between a and b (i.e., a < element < b).
std::vector<int> Foo8(const std::vector<int>& vec, int a, int b) {
    std::vector<int> result;
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(result), [a, b](int x) { return (x > a && x < b);});
    return result;
}

//Write a function that takes in a vector of strings and a string prefix, and returns a vector containing all of the strings in the original vector that start with prefix.
std::vector<std::string> Foo9(const std::vector<std::string>& str_list, const std::string& prefix) {
    std::vector<std::string> result;
    std::copy_if(str_list.begin(), str_list.end(), std::back_inserter(result), [&prefix](const std::string str) { return str.find(prefix) == 0;} );
    return result;
}

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

//Write a function that takes in a vector of integers and returns a vector containing all of the elements that are prime numbers.
std::vector<int> Foo10(const std::vector<int>& vec) {
    std::vector<int> result;
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(result), [](int x) { return isPrime(x); });
    return result;
}

//Write a function that takes in a vector of integers and returns a vector containing all of the elements that occur more than once in the original vector.
std::vector<int> Foo11(const std::vector<int>& vec) {
    std::vector<int> result;
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(result), [&](int x) { return std::count(vec.begin(), vec.end(), x) > 1; });
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
}

//Write a function that takes in a vector of integers and returns a boolean indicating whether the vector contains any adjacent duplicate elements (i.e., elements that are equal to their immediate neighbors).
bool Foo12(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    for( auto x = 0; x < vec.size() - 1; ++x) {
        if(vec[x] == vec[x+1])
            return true;
    }
    return false;
}

template <typename T>
void func_print(T y) {
    for(auto x : y) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}
// Implement a function that takes a two-dimensional array of integers as input and uses constexpr
// and template recursion to calculate the sum of all elements in the array.
template<std::size_t N, std::size_t M>
constexpr int SumArray(const int (&arr)[N][M]) {
    int sum = 0;
    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t j = 0; j < M; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
    std::vector<int> vec = {6,6,12,4,3,4,6,7,8};
    std::vector<std::string> vec_str = {"Tommy", "Gap", "Collins", "Morven"};

    std::cout << Foo(vec) << std::endl;
    std::cout << Foo2("OnnO") << std::endl;
    std::cout << Foo3(vec_str, "Gap") << std::endl;
    std::cout << Foo4(vec).at(0) << std::endl;
    std::cout << Foo5(vec_str).at(0) << std::endl;
    std::cout << Foo6(vec).at(0) << std::endl;
    std::cout << Foo8(vec,4,43).at(0) << std::endl;
    std::cout << Foo9(vec_str,"M").at(0) << std::endl;
    std::cout << Foo10(vec).at(1) << std::endl;
    func_print(Foo11(vec));
    std::cout << Foo12(vec) << std::endl;
}
