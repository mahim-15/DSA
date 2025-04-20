#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> element;
    int input;
    cout << "Enter elements (press -1 to stop):" << endl;
    while (true) {
        cin >> input;
        if (input == -1) break;
        element.push(input);
    }
    int choice, temp;
    while (true) {
        cout << "\n------- Menu -------" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete element (from front)" << endl;
        cout << "3. Print queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter element to insert: ";
            cin >> temp;
            element.push(temp);
        }
        else if (choice == 2) {
            if (element.empty()) {
                cout << "Queue is empty!" << endl;
            } else {
                element.pop();
                cout << "Element deleted from front successfully." << endl;
            }
        }
        else if (choice == 3) {
            if (element.empty()) {
                cout << "Queue is empty!" << endl;
            } else {
                cout << "Elements in the queue: ";
                queue<int> tempp = element; // Copy for printing
                while (!tempp.empty()) {
                    cout << tempp.front() << " ";
                    tempp.pop();
                }
                cout << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
