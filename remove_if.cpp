#include <algorithm>
#include <iostream>

void removeValue(int arr[], int size, int value) {
    // Using remove_if algorithm to move elements that are not equal to the input value to the front of the array
    auto newEnd = std::remove_if(arr, arr + size, [=](int x) { return x == value; });

    // Printing the original array
    std::cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Printing the array after remove_if
    std::cout << "Array after remove_if: ";
    for (auto i = arr; i != newEnd; i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    // Printing the elements that are removed
    std::cout << "Elements that are removed: ";
    for (auto i = newEnd; i != arr + size; i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 4, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    removeValue(arr, size, 4);
}
