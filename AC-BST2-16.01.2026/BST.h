

#include <iostream>
#include <stdexcept>

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T data) {
        left = nullptr;
        right = nullptr;
        this->data = data;
    }
};

template <typename T>
class BST {
    TreeNode<T>* root;

public:
    BST() {
        root = nullptr;
    }

    void add(T data) {
        TreeNode<T>* newNode = new TreeNode<T>(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        TreeNode<T>* temp = root;
        while (true) {
            if (data < temp->data) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            else {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    // FIXED: recursive add (was not compiling)
    TreeNode<T>* addRec(TreeNode<T>* node, T data) {
        if (node == nullptr) {
            return new TreeNode<T>(data);
        }
        if (data < node->data) {
            node->left = addRec(node->left, data);
        }
        else if (data > node->data) {
            node->right = addRec(node->right, data);
        }
        return node;
    }

    void addRec(T data) {
        root = addRec(root, data);
    }

    void printInorder(TreeNode<T>* node) {
        if (node == nullptr) return;
        printInorder(node->left);
        std::cout << node->data << " ";
        printInorder(node->right);
    }

    void printInorder() {
        printInorder(root);
    }

    // FIXED: preorder should call preOrder, not printInorder
    void preOrder(TreeNode<T>* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void printPreorder() {
        preOrder(root);
    }

    // FIXED: postorder should call postOrder, not printInorder
    void postOrder(TreeNode<T>* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }

    void printPostOrder() {
        postOrder(root);
    }

    // ==========================================================
    // REQUIRED (BST2): min in subtree, min address in tree, min value
    // ==========================================================

    // Find the address of node with minimum value in a subtree
    TreeNode<T>* findMinAddress(TreeNode<T>* node) {
        if (node == nullptr) return nullptr;
        TreeNode<T>* cur = node;
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        return cur;
    }

    // Find address of node with minimum value in tree
    TreeNode<T>* findAddressMin() {
        return findMinAddress(root);
    }

    // Find minimum value in tree
    T findMin() {
        TreeNode<T>* minNode = findAddressMin();
        if (minNode == nullptr) {
            throw std::runtime_error("BST is empty: no minimum value.");
        }
        return minNode->data;
    }
};
