#include <iostream>
#include <vector>

//Create a class called "Shape" that has a virtual function called "area()" that calculates the area of the shape. Create two derived classes called "Rectangle" and "Circle" that both override the "area()" function.
// Write a function that takes in a vector of Shape pointers and calculates the total area of all the shapes in the vector.

class Shape {
public:
    virtual double area() = 0;
};

class Rectangle : public Shape {
    const size_t x_dim;

public:
    Rectangle(size_t x_dim) : x_dim(x_dim) {}

    double area() override {
        return x_dim * x_dim;
    }
};

class Circle : public Shape {
    const size_t r_dim;

public:
    Circle(size_t r_dim) : r_dim(r_dim) {}

    double area() override {
        return 3.14 * r_dim * r_dim;
    }
};

int main() {

    Rectangle rectangle(2);
    Circle circle(2);

    std::vector<Shape*> vec = {&rectangle, &circle};
    double totalArea = 0;
    for(Shape* shape : vec) {
        totalArea += shape->area();
    }

    std::cout << totalArea;
    return 0;

}
