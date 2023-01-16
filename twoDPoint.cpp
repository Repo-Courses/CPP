#include <numeric>
#include <iostream>

// Create a class that represents a 2D point,
// with x and y coordinates. The class should have a constructor that takes the x and y coordinates as input, and overload the + operator to add two points together.
// The class should also overload the << operator to allow the point to be printed.

class twoDPoint {
public:
    twoDPoint(int x, int y) : x(x), y(y) {};

    twoDPoint operator+(const twoDPoint& other) {
        return twoDPoint(this->x + other.x, this->y + other.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const twoDPoint& point) {
        os << "x: " << point.x << " ";
        os << "y: " << point.y << " ";
        return os;
    }

private:
    int x;
    int y;
};

int main() {
    // Creating twoDPoint objects
    twoDPoint point1(1, 2);
    twoDPoint point2(3, 4);

    // Adding two points together
    twoDPoint point3 = point1 + point2;

    // Printing the points
    std::cout << "Point 1: " << point1 << std::endl;
    std::cout << "Point 2: " << point2 << std::endl;
    std::cout << "Point 3: " << point3 << std::endl;

    return 0;
}
