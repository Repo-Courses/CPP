class LinkedList {
public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}

    ~LinkedList() {
        Node* current = head_;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        if (!head_) {
            head_ = newNode;
            tail_ = newNode;
        } else {
            tail_->next = newNode;
            tail_ = newNode;
        }
    }

    void printList() {
        Node* current = head_;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };
    Node* head_;
    Node* tail_;
};

int main() {
    LinkedList list;
    list.push_back(5);
    list.push_back(7);
    list.push_back(10);
    list.printList();
    return 0;
}
