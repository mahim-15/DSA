#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Function to create a tree dynamically
Node* createNode() {
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    if (data == -1) return nullptr; // Base case for recursion

    Node* root = new Node(data);

    cout << "Enter left of " << data << endl;
    root->left = createNode();

    cout << "Enter right of " << data << endl;
    root->right = createNode();

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    cout << "Create a binary tree (Use -1 for NULL nodes)" << endl;
    Node* root = createNode();

    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
