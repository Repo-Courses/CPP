#include <iostream>
#include <vector>

//Write a function that overloads the "+" operator for a class called "ComplexNumber" that represents complex numbers.
//The function should be able to add two complex numbers together and return the result as a new complex number.
struct ComplexNumber {
    size_t first_num;
    size_t second_num;

    explicit ComplexNumber(const size_t first_num, const size_t second_num) : first_num(first_num), second_num(second_num) {};

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(this->first_num + other.first_num, this->second_num + other.second_num);
    }
};

int main() {
    ComplexNumber complexNumber(5,2);
    ComplexNumber complexNumber1(2,1);
    ComplexNumber complexNumber2 = complexNumber + complexNumber1;
    std::cout << complexNumber2.first_num << " " << complexNumber2.second_num << "i ";
}
