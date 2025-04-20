#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int roll;
    float marks;
};

// Function to sort students in descending order of marks
bool compareByMarks(const Student &a, const Student &b) {
    return a.marks > b.marks;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        
        cout << "\n=== Student Record Menu ===\n";
        cout << "1. Insert Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Students (Sorted by Marks)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from input buffer

        switch (choice) {
            case 1: {
                Student s;
                cout << "Enter name: ";
                getline(cin, s.name);

                cout << "Enter roll number: ";
                cin >> s.roll;

                cout << "Enter marks: ";
                cin >> s.marks;

                students.push_back(s);
                system("CLS");
                cout << "Student inserted.\n";
                break;
            }

            case 2: {
                if (students.empty()) {
                    cout << "No students to delete.\n";
                } else {
                    int pos;
                    cout << "Enter position to delete (0 to " << students.size() - 1 << "): ";
                    cin >> pos;

                    if (pos < 0 || pos >= students.size()) {
                        cout << "Invalid position.\n";
                    } else {
                        students.erase(students.begin() + pos);
                        system("CLS");
                        cout << "Student deleted.\n";
                    }
                }
                break;
            }

            case 3: {
                if (students.empty()) {
                    system("CLS");
                    cout << "No students to display.\n";
                } else {
                    system("CLS");
                    sort(students.begin(), students.end(), compareByMarks);
                    cout << "\nStudents Sorted by Marks (Descending):\n";
                    cout << "Name: " <<string(8,'-') << " Roll: " << string(8,'-') << " Marks: " << endl;
                    for (const auto &s : students) {
                        cout << s.name <<string(8,' ')
                             << s.roll << string(8,' ')
                             << s.marks << endl;
                    }
                }
                break;
            }

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
