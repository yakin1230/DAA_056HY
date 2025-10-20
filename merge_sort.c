#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int low, int mid, int high) {
    int n1 = mid - low + 1; 
    int n2 = high - mid;    
    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of left[], if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of right[], if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    
    // Free temporary arrays
    free(left);
    free(right);
}

void merge_sort(int *arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2; // Avoids overflow
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int num;
    printf("Enter number of elements to be sorted: ");
    scanf("%d", &num);
    
    // Input validation
    if (num <= 0) {
        printf("Error: Number of elements must be positive\n");
        return 1;
    }
    
    // Dynamically allocate array
    int *arr = (int *)malloc(num * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter %d elements to be sorted: ", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    
    merge_sort(arr, 0, num - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free allocated memory
    free(arr);
    return 0;
}