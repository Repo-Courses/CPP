#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* pointer = arr; // Assign the address of the first element of the array to the pointer

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    *pointer = 10; // Using the pointer to change the value of the first element of the array
    cout << "Array after changing the first element: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    pointer += 2; // Moving the pointer to the third element of the array
    cout << "Third element of the array: " << *pointer << endl;

    pointer -= 1; // Moving the pointer back to the second element of the array
    *pointer = 20; // Using the pointer to change the value of the second element of the array
    cout << "Array after changing the second element: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
