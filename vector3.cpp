#include <iostream>


class Vector
{
public:
    Vector(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    double x, y, z;
};

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    return Vector(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector operator*(double lhs, const Vector& rhs)
{
    return Vector(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

int main()
{
    Vector v1(1, 2, 3), v2(4, 5, 6), v3;
    v3 = v1 + v2;
    std::cout << "v3 = (" << v3.x << ", " << v3.y << ", " << v3.z << ")\n";
    v3 = 2 * v1;
    std::cout << "v3 = (" << v3.x << ", " << v3.y << ", " << v3.z << ")\n";
    return 0;
}
