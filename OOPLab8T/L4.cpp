#include <iostream>
#include <stack>

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(const T& value)
        : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTreeIterator;

template <typename T>
class BinaryTree {
private:
    BinaryTreeNode<T>* root;

public:
    BinaryTree() : root(nullptr) {}

    void addNode(const T& value) {
        BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(value);

        if (root == nullptr) {
            root = newNode;
        }
        else {
            BinaryTreeNode<T>* current = root;
            BinaryTreeNode<T>* parent = nullptr;

            while (current != nullptr) {
                parent = current;

                if (value < current->data) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }

            if (value < parent->data) {
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }
        }
    }

    BinaryTreeIterator<T> begin();
    BinaryTreeIterator<T> end();
};

template <typename T>
class BinaryTreeIterator {
private:
    BinaryTreeNode<T>* current;
    std::stack<BinaryTreeNode<T>*> nodeStack;

public:
    BinaryTreeIterator(BinaryTreeNode<T>* root) : current(root) {
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;
        }

        if (!nodeStack.empty()) {
            current = nodeStack.top();
            nodeStack.pop();
        }
    }

    BinaryTreeIterator<T>& operator++() {
        if (current->right != nullptr) {
            current = current->right;

            while (current != nullptr) {
                nodeStack.push(current);
                current = current->left;
            }
        }
        else if (!nodeStack.empty()) {
            current = nodeStack.top();
            nodeStack.pop();
        }
        else {
            current = nullptr;
        }

        return *this;
    }

    BinaryTreeIterator<T>& operator--() {
        if (current->left != nullptr) {
            current = current->left;

            while (current != nullptr) {
                nodeStack.push(current);
                current = current->right;
            }
        }
        else if (!nodeStack.empty()) {
            current = nodeStack.top();
            nodeStack.pop();
        }
        else {
            current = nullptr;
        }

        return *this;
    }

    T& operator*() {
        return current->data;
    }

    bool operator==(const BinaryTreeIterator<T>& other) const {
        return current == other.current;
    }

    bool operator!=(const BinaryTreeIterator<T>& other) const {
        return !(*this == other);
    }
};

template <typename T>
BinaryTreeIterator<T> BinaryTree<T>::begin() {
    return BinaryTreeIterator<T>(root);
}

template <typename T>
BinaryTreeIterator<T> BinaryTree<T>::end() {
    return BinaryTreeIterator<T>(nullptr);
}

void  task4() {
    BinaryTree<int> tree;
    tree.addNode(8);
    tree.addNode(9);
    tree.addNode(2);
    tree.addNode(1);
    tree.addNode(6);
    tree.addNode(3);
    tree.addNode(4);

    for (BinaryTreeIterator<int> it = tree.begin(); it != tree.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

   
}
