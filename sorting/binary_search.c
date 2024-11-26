#include <stdio.h>



int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid =  (right + left) / 2;
        // executeAtMid(mid, arr, size);

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, i;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];  // This works in C99 or later, but the size must be determined at runtime.
    
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    int target;
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target); 

    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array\n", target);
    }

    return 0;
}
