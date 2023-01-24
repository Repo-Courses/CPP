#include <iostream>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            std::swap(arr[j+1], arr[j]);
            j = j-1;
        }
        arr[j+1] = key;
    }
}

// Given an array of integers and a value x, write a function using the std::partition algorithm to rearrange the elements in the array such that all elements less than x come before all elements greater than or equal to x.
auto partitionArray(int* arr, int size, int x) {
    auto pivot = std::partition(arr, arr + size, [x](int i){ return i < x; });
    // pivot now points to the first element that is greater or equal to x
    return pivot;
}

// Given an array of strings and a string value s, write a function using the std::partition algorithm to rearrange the elements in the array such that all elements that are lexicographically smaller than s come before all elements that are lexicographically greater than or equal to s.
auto partitionStringArray(std::string* arr, int size, char s) {
    auto pivot = std::partition(arr, arr + size, [s](const std::string& str) { return !str.empty() && str[0] < s; });
    return pivot;
}

template<typename T>
auto partitionStr(T* arr, int size, T x) {
    auto pivot = std::partition(arr, arr + size, [x](const T& num) { return num < x; });
    return pivot;
}

#include <iostream>
#include <algorithm>
#include <string>

/*
 *  The main advantage of using a template function is that it allows you to use the same function for different types of elements, like int, float, std::string, etc.
    The main drawback of using a template function is that it increases the binary size of your code since it generates a version of the function for each type that is used. This may increase the memory usage of your program and may also increase the build time of your code.
    Another drawback is that you need to be very careful with the comparision operator used in the lambda function passed to std::partition, because not all types have the same behaviour for comparison operators.
 */

template<typename T>
auto partitionArray(T* arr, int size, T x) {
    auto pivot = std::partition(arr, arr + size, [x](const T& num) { return num < x; });
    return pivot;
}

// template <typename T = std::byte, unsigned Capacity = 1024>,   syntax: template_parameter = default

template <typename T>
void swap(T& a, T& b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

class A { };

template <typename C, typename T>
class SearchAlgorithm {
    void find(const C& container, const T& value) {
        /* do linear search */
    } };



int main() {
    std::string arr[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape"};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::string x = "fig";
    auto pivot = partitionStr(arr, size, x);
    for (auto i = arr; i != pivot; ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;
    for (auto i = pivot; i != arr + size; ++i)
        std::cout << *i << ' ';

    A a1;
    A a2;
    swap<A>(a1, a2);
    swap(a1, a2);

    return 0;
}


