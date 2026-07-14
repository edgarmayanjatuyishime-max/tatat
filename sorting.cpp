// Task 6: Bubble Sort & Insertion Sort
// Time Complexities: Bubble Sort: O(n^2), Insertion Sort: O(n^2)

#include <stdio.h>

void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void bubble_sort_trace(int arr[], int size) {
    printf("Original array: ");
    print_array(arr, size);
    
    for (int i = 0; i < size; i++) {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // Print the array state after each complete pass
        printf("Pass %d: ", i + 1);
        print_array(arr, size);
        if (!swapped) {
            break; // Early exit if already sorted
        }
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int unsorted1[7] = {64, 34, 25, 12, 22, 11, 90};
    int size = 7;
    
    printf("--- 1. Bubble Sort with Trace Step Prints ---\n");
    bubble_sort_trace(unsorted1, size);
    
    int unsorted2[7] = {64, 34, 25, 12, 22, 11, 90};
    printf("\n--- 2. Insertion Sort ---\n");
    printf("Original array: ");
    print_array(unsorted2, size);
    
    insertion_sort(unsorted2, size);
    printf("Sorted array:   ");
    print_array(unsorted2, size);
    
    return 0;
}
