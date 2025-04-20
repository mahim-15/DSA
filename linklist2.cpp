#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // Data in the node
    Node* next;     // Pointer to the next node
};

// Function to append a node at the end of the list
void append(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to delete a node with a specific value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node with value " << value << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value not found in the list!" << endl;
    } else {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Deleted node with value " << value << endl;
    }
}

// Function to insert a node after a specific value
void insertAfter(Node*& head, int target, int value) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Target value not found in the list!" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Inserted " << value << " after " << target << endl;
}

// Function to swap two nodes in the list
void swapNodes(Node*& head, int val1, int val2) {
    if (val1 == val2) {
        cout << "Both values are the same; no need to swap!" << endl;
        return;
    }

    Node *prev1 = nullptr, *curr1 = head;
    Node *prev2 = nullptr, *curr2 = head;

    // Find the two nodes
    while (curr1 != nullptr && curr1->data != val1) {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    while (curr2 != nullptr && curr2->data != val2) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    // If either value is not found
    if (curr1 == nullptr || curr2 == nullptr) {
        cout << "One or both values not found in the list!" << endl;
        return;
    }

    // Swap the nodes
    if (prev1 != nullptr) {
        prev1->next = curr2;
    } else {
        head = curr2;
    }

    if (prev2 != nullptr) {
        prev2->next = curr1;
    } else {
        head = curr1;
    }

    Node* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;

    cout << "Swapped " << val1 << " and " << val2 << endl;
}

// Function to free the memory of the list
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "List deleted!" << endl;
}

// Main function
int main() {
    Node* head = nullptr;
    int choice, value, target, val1, val2;

    do {
        cout << "\n1. Append\n2. Display\n3. Delete Node\n4. Insert After\n5. Swap Nodes\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to append: ";
                cin >> value;
                append(head, value);
                break;

            case 2:
                display(head);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;

            case 4:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                insertAfter(head, target, value);
                break;

            case 5:
                cout << "Enter first value to swap: ";
                cin >> val1;
                cout << "Enter second value to swap: ";
                cin >> val2;
                swapNodes(head, val1, val2);
                break;

            case 6:
                deleteList(head);
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}