#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

void Foo(std::vector<std::unique_ptr<int>>& vec) {
    std::sort(vec.begin(), vec.end(), [](const std::unique_ptr<int>& p1, const std::unique_ptr<int>& p2){ return *p1 < *p2;});
}

template<typename T>
std::vector<T> uniqueElements(std::vector<T> input) {
    std::unordered_set<T> uniqueElements;
    for (auto& element : input) {
        uniqueElements.insert(element);
    }
    return std::vector<T>(uniqueElements.begin(), uniqueElements.end());
}


int main() {
    std::vector<std::unique_ptr<int>> vec;
    vec.push_back(std::make_unique<int>(5));
    vec.push_back(std::make_unique<int>(3));
    vec.push_back(std::make_unique<int>(1));
    vec.push_back(std::make_unique<int>(4));
    vec.push_back(std::make_unique<int>(2));
    std::cout << "Original order: " << std::endl;
    for (const auto& ptr : vec) {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
    Foo(vec);
    std::cout << "Sorted order: " << std::endl;
    for (const auto& ptr : vec) {
        std::cout << *ptr << " ";
    }
    
    int main() {
    std::vector<int> input = {1, 2, 3, 4, 5, 2, 3, 4, 5};
    std::vector<int> output = uniqueElements(input);
    std::cout << "Original vector: ";
    for (auto& element : input) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << "Unique elements vector: ";
    for (auto& element : output) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}
