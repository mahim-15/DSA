#include <iostream>
using namespace std;

int main() {
    int n, element, count = 0;

    // Ask for number of elements
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];         // Declare a fixed-size array
    int pos[n];         // Array to store positions

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input element to search
    cout << "Enter the element to search: ";
    cin >> element;

    // Search and store positions
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            pos[count] = i + 1;  // Save the 1-based index
            count++;
        }
    }

    // Output result
    if (count == 0) {
        cout << "Element " << element << " not found in the array.\n";
    } else {
        cout << "Element " << element << " occurrence " << count << " times.\n";
        cout << "Positions (1-based index): ";
        for (int i = 0; i < count; i++) {
            cout << pos[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
