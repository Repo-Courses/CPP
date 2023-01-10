#include <vector>
#include <memory>
#include <iostream> 

class Queue {
public:
    Queue() = default;

    // push an int to the back of the queue
    void push(int value) {
        m_queue.emplace_back(std::make_shared<int>(value));
    }

    // pop the front int from the queue
    void pop() {
        if (!m_queue.empty()) {
            m_queue.erase(m_queue.begin());
        }
    }

    // returns the front int of the queue
    int front() {
        if (!m_queue.empty()) {
            return *m_queue.front();
        }
    }

private:
    std::vector<std::shared_ptr<int>> m_queue;
};

int main() {
    Queue q;
    q.push(3);
    q.push(5);
    q.push(7);
    std::cout << q.front() << std::endl; // prints 3
    q.pop();
    std::cout << q.front() << std::endl;
}
