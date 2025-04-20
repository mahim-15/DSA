#include <iostream>
#include <ctime>
using namespace std;

class A {
public:
    int* arr;
    int Size;

    A(int s) : Size(s) {
        arr = new int[Size];
        srand(time(0)); // Seed the random number generator
        for (int i = 0; i < Size; i++) {
            arr[i] = rand() % 10; // Fill with random values 0–9
        }
    }

    void searchValue(int value) {
        int count = 0;
        cout << "Value " << value << " found at positions: ";
        for (int i = 0; i < Size; i++) {
            if (arr[i] == value) {
                cout << i + 1 << " "; // 1-based index
                count++;
            }
        }
        if (count == 0) {
            cout << "None";
        }
        cout << "\nOccurrences: " << count << endl;
    }

    void displayArray() {
        for (int i = 0; i < Size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~A() {
        delete[] arr;
    }
};

int main() {
    int a, value;

    cout << "Enter the size of the array: ";
    cin >> a;

    A obj(a);

    cout << "Generated array: ";
    obj.displayArray();

    cout << "\nEnter a value to search: ";
    cin >> value;

    obj.searchValue(value);

    return 0;
}

