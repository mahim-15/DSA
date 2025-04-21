#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) {
        data = v;
        next = NULL;
    }
};

void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertEnd(Node*& head, int val) {
    if (head == NULL) {
        insertHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteByValue(Node*& head, int val) {
    if (head == NULL) return;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data != val) {
        curr = curr->next;
    }

    if (curr->next == NULL) {
        cout << "Value not found.\n";
        return;
    }

    Node* toDelete = curr->next;
    curr->next = curr->next->next;
    delete toDelete;
}

int main() {
    Node* head = NULL;
    int choice, value;

    do {
        system("CLS");  // Optional: for Windows console clearing
        cout << "Current List: ";
        traverse(head);

        cout << "\nMenu:\n";
        cout << "1. Insert Elements\n";
        cout << "2. Delete Element by Value\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter values to insert (-1 to stop): ";
                cin >> value;
                while (value != -1) {
                    insertEnd(head, value);
                    cin >> value;
                }
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByValue(head, value);
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();

    } while (choice != 3);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
