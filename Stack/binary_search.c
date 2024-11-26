#include <stdio.h>

void executeAtMid(int mid, int arr[], int size) {

    printf("Checking middle element at index %d: %d\n", mid, arr[mid]);
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        executeAtMid(mid, arr, size);

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

int main() {//sorted array only
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array\n", target);
    }

    return 0;
}
