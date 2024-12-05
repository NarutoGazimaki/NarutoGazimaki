#include <stdio.h>


int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (arr[mid] == target) {
            return mid;  
        }
        else if (arr[mid] < target) {
            low = mid + 1;  
        }
        else {
            high = mid - 1;  
        }
    }
    
    return -1; 
}


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];  
    
  
    printf("Enter %d elements: \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, size);

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
