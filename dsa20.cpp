#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int key;
    Node *left, *right;

    Node(int data) {
        key = data;
        left = right = nullptr;
    }
};

// Insert a node into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

// Search a key in BST
bool search(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    return key < root->key ? search(root->left, key) : search(root->right, key);
}

//Find the minimum value node
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) current = current->left;
    return current;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    // root = insert(root, 40);
    // root = insert(root, 60);
    // root = insert(root, 80);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    cout<<"$";

    while (true)
    {
        /*cout << "Inorder traversal: ";
            inorder(root);
            cout << endl; */

            cout<<endl;
            cout<<endl;

        cout<<"1. search \n2. insert \n3. delete \n4. exit \nEnter your choice: "<<endl;
        int n;
        cin>>n;
        if(n==1)
        {
            
            int s;
            cout<<"enter data to search: ";cin>>s;
            cout << "Search "<<s << (search(root, s) ? ": Found" : ": Not Found") << endl;
            
        }
        else if(n==2){

            int s;
            cout<<"enter data to Insert: ";cin>>s;
            root = insert(root, s);

            cout << "Inorder traversal after Inserting: ";
            inorder(root);
            cout << endl;
        }
        else if(n==3){

            int s;
            cout<<"enter data to Delete: ";cin>>s;
            root = deleteNode(root, s);

            cout << "Inorder traversal after deleting: ";
            inorder(root);
            cout << endl;
        }
        else if(n==4){
            cout<<"Operation terminated & Exit"<<endl;
            break;
        }
        else
        cout<<"Invalid Input, please try again"<<endl;
    }
    

    return 0;
}
