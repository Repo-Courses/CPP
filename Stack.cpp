#include <numeric>
#include <iostream>
#include <vector>

// Create a class that represents a stack of integers, using a vector as the underlying container. The class should have a constructor, a destructor, and functions to push and pop elements from the stack.
// The class should also have a function that uses the std::find_if algorithm and a lambda function to find the first element that is greater than a given value.

class Stack {
public:
    Stack(std::vector<int> vec) : vec(vec) {};

    ~Stack() { }

    void pop() {
        if (!vec.empty())
            vec.pop_back();
        else
            std::cout << "Stack is empty. " << std::endl;
    }

    int top() {
        if (!vec.empty())
            return vec.back();
        else
            return -1;
    }

    void push(int element) {
        if(std::find(vec.begin(), vec.end(), element) == vec.end()){
            vec.push_back(element);
        }
    }

    int greaterThan(int value) {
        auto it = std::find_if(vec.begin(), vec.end(), [value](int x) { return x > value; });
        return (it != vec.end()) ? *it : -1;
    }

private:
    std::vector<int> vec;
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Stack stack(vec);

    // Push new elements to the stack
    stack.push(6);
    stack.push(7);

    // Pop the last element from the stack
    stack.pop();

    // Print the top element of the stack
    std::cout << "Top element: " << stack.top() << std::endl;

    // Find the first element greater than a given value
    int value = 4;
    int firstGreater = stack.greaterThan(value);
    if (firstGreater == -1)
        std::cout << "No elements greater than " << value << " found." << std::endl;
    else
        std::cout << "First element greater than " << value << ": " << firstGreater << std::endl;

    return 0;
}
