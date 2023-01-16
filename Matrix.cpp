#include <numeric>
#include <string>
#include <iostream>

// Create a class that represents a matrix of integers, with rows and columns. The class should have a constructor that takes the number of rows and columns as input,
// and a destructor that releases the memory of the matrix.
// The class should also have a function that uses the std::transform algorithm and a lambda function to square all elements of the matrix.

class Matrix {
public:
    int getRows()  { return rows_; }
    int getCols()  { return cols_; }

    int& operator()(int i, int j) {
        return data_[i][j];
    }

    void squareElements() {
        for(int i = 0; i < rows_; ++i) {
            std::transform(data_[i], data_[i] + cols_, data_[i], [](int x) { return x * x; });
        }
        //Another solution
        //for (int i = 0; i < rows_; ++i) {
        //        std::for_each(data_[i], data_[i] + cols_, [](int &x) { x *= x; });
        //    }
    }


    Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
        data_ = new int*[rows_];
        for(int i = 0; i < rows; ++i) {
            data_[i] = new int[cols_];
        }
    }

    ~Matrix() {
        for(int i = 0; i < rows_; i++) {
            delete[] data_[i];
        }
        delete data_;
    }

private:
    int rows_;
    int cols_;
    // int** data_; means that data_ is a pointer to a pointer of type int, it's used to store the 2D array of integers that represents the matrix.
    int** data_;
};

int main() {
    // Create a 3x4 matrix
    Matrix matrix(3, 4);

    // Fill the matrix with some values
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            matrix(i, j) = i + j;
        }
    }

    // Print the original matrix
    std::cout << "Original matrix:" << std::endl;
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << std::endl;
    }

    // Square all elements of the matrix
    matrix.squareElements();

    // Print the squared matrix
    std::cout << "Squared matrix:" << std::endl;
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

