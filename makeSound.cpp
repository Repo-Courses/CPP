#include <iostream>
#include <vector>

//Create an abstract class called "Animal" that has a pure virtual function called "makeSound()". Create two derived classes called "Dog" and "Cat" that both override the "makeSound()" function.
//Write a function that takes in a vector of Animal pointers and calls the "makeSound()" function on each animal in the vector.
struct Animal {
    virtual void makeSound() = 0;
};

struct Cat : Animal {
    void makeSound() override {
        std::cout << "Miyav" << std::endl;
    }
};

struct Dog : Animal {
    void makeSound() override {
        std::cout << "Hav" << std::endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    std::vector<Animal*> vec = {&dog, &cat};

    for(auto animal : vec) {
        animal->makeSound();
    }
}
