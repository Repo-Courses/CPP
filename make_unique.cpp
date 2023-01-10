#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

void Foo(std::vector<std::unique_ptr<int>>& vec) {
    std::sort(vec.begin(), vec.end(), [](const std::unique_ptr<int>& p1, const std::unique_ptr<int>& p2){ return *p1 < *p2;});
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
    return 0;
}
