#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

//Create a generic function that takes in two parameters of any type and returns the larger of the two.
template<typename T>
auto larger(T& t1, T& t2) {
    return t1 <= t2 ? t2 : t1;

}

//Create a generic lambda function that takes in a container and returns the average value of the elements in the container.
template<typename T>
double average(const std::vector<T>& vec) { return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();};


//Write a template class that implements a stack data structure, with a push and pop method.
template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(T element) {
        elements.push_back(element);
    }

    T pop() {
        if(elements.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T popped = elements.back();
        elements.pop_back();
        return popped;
    }

    T top() {
        if (elements.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return elements.back();
    }

    bool empty() {
        return elements.empty();
    }
};


int main() {
    std::vector<int> intVector {1, 2, 3, 4};
    std::vector<double> doubleVector {1.1, 2.2, 3.3};
    std::cout<<average(intVector)<<std::endl;
    std::cout<<average(doubleVector)<<std::endl;

    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    while (!intStack.empty()) {
        std::cout << intStack.pop() << std::endl;
    }

    Stack<std::string> stringStack;
    stringStack.push("Hi");
    stringStack.push("world");

    while (!stringStack.empty()) {
        std::cout << stringStack.pop() << std::endl;
    }


    return 0;


}
