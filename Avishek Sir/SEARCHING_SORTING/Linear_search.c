#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Target found at index i
        }
    }
    return -1;  // Target not found
}

int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];  // Declare array with user-defined size
    
    // Input array elements from the user
    printf("Enter %d elements: \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
