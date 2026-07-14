// Task 5: Linear Search vs Binary Search
// Time Complexities: Linear Search: O(n), Binary Search: O(log n)

#include <stdio.h>

int linear_search(int arr[], int size, int target, int* out_comps) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == target) {
            *out_comps = comparisons;
            return i;
        }
    }
    *out_comps = comparisons;
    return -1;
}

int binary_search(int arr[], int size, int target, int* out_comps) {
    int low = 0;
    int high = size - 1;
    int comparisons = 0;
    
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            *out_comps = comparisons;
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    *out_comps = comparisons;
    return -1;
}

int main() {
    // Sorted list of exactly 20 items
    int dataset[20] = {3, 7, 12, 19, 21, 26, 32, 38, 44, 49, 55, 61, 67, 73, 79, 84, 89, 93, 97, 100};
    int size = 20;
    int target_value = 89;
    
    printf("Dataset (20 sorted items): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dataset[i]);
    }
    printf("\nTarget value to find: %d\n\n", target_value);
    
    int lin_comps = 0;
    int lin_index = linear_search(dataset, size, target_value, &lin_comps);
    printf("--- Linear Search ---\n");
    printf("Found at Index: %d\n", lin_index);
    printf("Comparisons taken: %d\n", lin_comps);
    
    int bin_comps = 0;
    int bin_index = binary_search(dataset, size, target_value, &bin_comps);
    printf("\n--- Binary Search ---\n");
    printf("Found at Index: %d\n", bin_index);
    printf("Comparisons taken: %d\n", bin_comps);
    
    return 0;
}
