#include <bits/stdc++.h>
using namespace std;  

typedef struct mylist {
    int data;
    struct mylist *next;
} node;

void insert(node *S, int data) {
    while (S->next != NULL) {
        S = S->next;
    }
    S->next = new node; 
    S->next->data = data;
    S->next->next = NULL;
}

void display(node *S) {
    while (S != NULL) {
        cout << S->data << " ";
        S = S->next;
    }
    cout << endl;
}

void deleteNode(node *&S, int data) { 
    node *temp = S;
    if (S != NULL && S->data == data) {
        S = S->next; 
        delete temp; 
        return;
    }

    while (temp != NULL && temp->next != NULL) {
        if (temp->next-> data == data) {
            node *delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode; // Free the deleted node
            return;
        }
        temp = temp->next;
    }
}

void clearScreen() {
    // Clearing screen is platform-dependent. A better way would be to avoid system calls.
    #ifdef _WIN32
        system("cls");
    #else
        cout << "\033[2J\033[1;1H"; // Clear screen on Unix-like systems
    #endif
}

int main() {
    node* first = new node; // Initialize using new
    first->next = NULL;  

    int choice, data;

    while (true) {
        clearScreen(); 

        cout << "Menu:\n";
        cout << "1. Insert Data\n";
        cout << "2. Delete Data\n";
        cout << "3. Display Data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  
                cout << "Enter data to insert: ";
                cin >> data;
                insert(first, data);
                break;

            case 2:  
                cout << "Enter data to delete: ";
                cin >> data;
                deleteNode(first, data);
                break;

            case 3:  
                cout << "List: ";
                display(first);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 4:  
                cout << "Exiting program.\n";
                return 0;  // Use return for exiting main

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
