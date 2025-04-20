#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int arr[MAX_SIZE];
    int size = 0;

    // Open unsorted_array.txt for reading
    inputFile = fopen("mahim11.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open unsorted_array.txt for reading.\n");
        return 1;
    }

    // Read integers from the file
    while (fscanf(inputFile, "%d", &arr[size]) == 1 && size < MAX_SIZE) {
        size++;
    }

    fclose(inputFile); // Close input file

    // Sort the array
    bubbleSort(arr, size);

    // Open sorted_array.txt for writing
    outputFile = fopen("sorted_array.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open sorted_array.txt for writing.\n");
        return 1;
    }

    printf("\nSorted array: ");
    // Write sorted data to output file
    for (int i = 0; i < size; ++i) {
        fprintf(outputFile, "%d ", arr[i]);
        printf("%d ",arr[i]);
    }

    fclose(outputFile); // Close output file

    printf("\nSorting completed. Sorted data written to sorted_array.txt\n");

    return 0;
}
