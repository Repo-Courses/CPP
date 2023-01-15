#include <numeric>
#include <iostream>

// Create a class that uses RAII to manage the memory of a dynamically allocated array of integers.
// The class should have a constructor that takes the size of the array as input, and a destructor that releases the memory of the array.
// The class should also have a function that uses the std::for_each algorithm and a lambda function to print the elements of the array.

class DynamicArray {
public:
    DynamicArray(int size) : size_(size), data_(new int[size]) { }

    ~DynamicArray() {
        delete[] data_;
    }

    int& operator[](int index) {
        return data_[index];
    }

    int size() const { return size_; }

    void printr() {
        std::for_each(this->data_, this->data_ + this->size_, [&](int value) { std::cout << value << " "; } );
    }

private:
    int size_;
    int* data_;
};

int main() {
    // Create a dynamic array with a size of 5
    DynamicArray arr(5);
    // Fill the array with values
    for(int i = 0; i < 5; i++)
        arr[i] = i+1;
    // Print the elements of the array
    arr.printr();
    std::cout<<std::endl;
    return 0;
}
