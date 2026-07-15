// Task 1: Arrays - Student Marks
// Time Complexities: Read: O(1), Update: O(1), Traverse: O(n), Find Max: O(n), Insert: O(n)

#include <stdio.h>

void traverse_and_print(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int read_value(int arr[], int size, int index) {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    printf("Error: Index out of bounds\n");
    return -1;
}

void update_value(int arr[], int size, int index, int new_value) {
    if (index >= 0 && index < size) {
        arr[index] = new_value;
    } else {
        printf("Error: Index out of bounds\n");
    }
}

int find_maximum(int arr[], int size) {
    if (size <= 0) return -1;
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

// Fixed-size array manual insertion logic
int insert_value(int arr[], int size, int max_capacity, int index, int value) {
    if (size >= max_capacity) {
        printf("Error: Array is full, cannot insert.\n");
        return size;
    }
    if (index < 0 || index > size) {
        printf("Error: Insertion index out of bounds.\n");
        return size;
    }
    
    // Shift elements to the right from the end down to the target index
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Place new value in the freed slot
    arr[index] = value;
    return size + 1;
}

int main() {
    // Array declared with one extra empty slot in advance (capacity 6, holding 5 values initial)
    int marks[6] = {85, 92, 78, 90, 88};
    int current_size = 5;
    int max_capacity = 6;
    
    printf("--- 1. Initial Array ---\n");
    traverse_and_print(marks, current_size);
    
    printf("\n--- 2. Read Value at Index 2 ---\n");
    printf("Value at index 2: %d\n", read_value(marks, current_size, 2));
    
    printf("\n--- 3. Update Value at Index 2 to 82 ---\n");
    update_value(marks, current_size, 2, 82);
    traverse_and_print(marks, current_size);
    
    printf("\n--- 4. Find Maximum Value ---\n");
    printf("Maximum mark: %d\n", find_maximum(marks, current_size));
    
    printf("\n--- 5. Manual Insertion ---\n");
    int target_index = 2;
    int new_mark = 95;
    
    printf("Array before insertion:\n");
    traverse_and_print(marks, current_size);
    
    current_size = insert_value(marks, current_size, max_capacity, target_index, new_mark);
    
    printf("Array after inserting %d at index %d:\n", new_mark, target_index);
    traverse_and_print(marks, current_size);
    
    return 0;
}
