#include <numeric>
#include <string>
#include <iostream>

/*
    Write a function that takes in a Vector object and a value, and replaces all elements in the Vector with the given value.
    Write a function that takes in a Vector object and a value, and adds the value to the end of the Vector.
    Write a function that takes in a Vector object, and returns a new Vector object that contains all elements of the original Vector in reverse order.
    Write a function that takes in two Vector objects, and returns a new Vector object that contains all elements of both the original Vector in sorted order.
    Write a function that takes in a Vector object and a value, and returns the index of the first occurrence of the value in the Vector, or -1 if the value is not present in the Vector.
    Write a function that takes in a Vector object and returns a new Vector object that only contains unique elements of the original Vector.
    Write a function that takes in a Vector object and a value, and removes the first occurrence of the value in the Vector if it is present.
 */

template<typename T>
struct Vector {
    size_t size;
    T* values;

    // default c-tor
    Vector() : size(0), values(nullptr) {}

    // c-tor #1
    Vector(size_t size) : size(size), values(new T[size])
    {
        for(int i=0; i<size; ++i)
            values[i] = T();
    }

    // d-tor
    ~Vector() {
        delete[] values;
    }

    // copy-const
    Vector(const Vector<T>& other) : size(other.size), values(new T[size]) {
        for (int i = 0; i < size; ++i) {
            values[i] = other.values[i];
        }
    }

    // move-const

    Vector(Vector<T>&& other) : size(other.size), values(other.values) {
        other.values = nullptr;
    }


    /*
     *  another way to implement move const.
     *  Vector(const Vector<T>&& other) : size(std::move(other.size)), values(std::move(other.values))
            {
                other.values = nullptr;
                other.size = 0;
            }
     *
     */

    // move assignment
    Vector<T>& operator=(Vector<T>&& other)
    {
        size = other.size;
        delete[] values;
        values = other.values;
        other.values = nullptr;
        return *this;
    }

    T& at(size_t index) { return values[index];}

    T& operator[](size_t index) { return values[index]; }

    T& operator[](size_t index) const { return values[index]; }

};

Vector<int> doSomething()
{
    auto v = Vector<int>(1000);
    // ...
    return v;
}

int main(int argc, char* argv[])
{
    // k is being copy constructed from return value of doSomething()
    // hint: there is a mechanism called copy elison that partially solves this costly behavior but...
    auto k = doSomething(); // copy c-tor from returned value of doSomething()
    k = doSomething(); // copy assignment from returned value of doSomething()

    auto v1 = Vector<int>(10);

    v1.at(0) = 1000;
    v1[1] = 2000;

    auto v2 = Vector<int>();
    auto v3 = Vector<int>();

    v2 = std::move(v1); // copy assignment: why? v2 already exists, has been constructed. we assign on top of it

    v3 = std::move(v2 = std::move(v1)); // chained copy assignment
//    v3.operator(v2.operator=(v1));

    auto v4 = Vector<int>(v1); // copy c-tor: why? v4 is being constructed right now from v1

//    auto v5 = (Vector&&)v4;
    auto v5 = std::move(v4); // move c-tor: why? v5 is being constructed right now stealing from v4

    std::cout << v1.at(1) << std::endl;

    return 0;
}

