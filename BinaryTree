class BinaryTree {
public:
    //Node structure
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };
    //pointer to the root of the tree
    Node* root;

    // constructor
    BinaryTree() : root(nullptr) {}

    // insert a value into the tree
    void insert(int value) {
        root = insert(root, value);
    }

private:
    // recursive helper function for insert
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }
};

#include <iostream>

int main() {
    BinaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Values have been inserted into the tree" << std::endl;

    return 0;
}
