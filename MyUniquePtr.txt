#include <iostream>

template <typename T>

class MyUniquePtr  {
public:

    explicit MyUniquePtr(T* ptr = nullptr) : m_ptr(ptr) {};

    ~MyUniquePtr() {
        delete m_ptr;
    };

    T* get() const {
        return m_ptr;
    }

    // reset method
    void reset(T* ptr = nullptr) {
        if (m_ptr != ptr) {
            delete m_ptr;
            m_ptr = ptr;
        }
    }

    // release method
    T* release() {
        T* ptr = m_ptr;
        m_ptr = nullptr;
        return ptr;
    }

    // operators overload
    T& operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

private:
    T* m_ptr;
};

int main() {
    MyUniquePtr<int> up(new int(10));
    std::cout << *up << std::endl;  // prints 10
    up.reset(new int(20));
    std::cout << *up << std::endl;  // prints 20
    int* raw_ptr = up.release();
    std::cout << *raw_ptr << std::endl;  // prints 20
    delete raw_ptr;
}
