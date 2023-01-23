#include <iostream>

class MyValue {
    int value;

public:
    MyValue(int v) : value(v) {}

    // Copy constructor
    MyValue(const MyValue& other) : value(other.value) {
        std::cout << "copy-constructed" << std::endl;
    }

    // Move constructor
    MyValue(MyValue&& other) : value(std::move(other.value)) {
        std::cout << "move-constructed" << std::endl;
    }

    // Copy assignment operator
    MyValue& operator=(const MyValue& other) {
        value = other.value;
        std::cout << "copy-assigned" << std::endl;
        return *this;
    }

    // Move assignment operator
    MyValue& operator=(MyValue&& other) {
        value = std::move(other.value);
        std::cout << "move-assigned" << std::endl;
        return *this;
    }

    int getValue() const { return value; }
};

MyValue getRValue() {
    return MyValue(10);
}

int main() {
    MyValue lValue(5);
    MyValue lValue2(lValue); // copy-constructed
    MyValue lValue3(std::move(lValue)); // move-constructed
    lValue3 = lValue2; // copy-assigned
    lValue3 = std::move(lValue2); // move-assigned
    MyValue rValue(getRValue()); // move-constructed
    return 0;
}
