#include <stdio.h>

// Structure to hold both minimum and maximum values
typedef struct {
    int min;
    int max;
} MinMax;

// Function to find the minimum and maximum using divide and conquer
MinMax findMinMax(int arr[], int left, int right) {
    MinMax result, leftResult, rightResult;

    // Base case: If there is only one element
    if (left == right) {
        result.min = arr[left];
        result.max = arr[left];
        return result;
    }

    // Base case: If there are two elements
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            result.min = arr[left];
            result.max = arr[right];
        } else {
            result.min = arr[right];
            result.max = arr[left];
        }
        return result;
    }

    // Divide the array into two halves
    int mid = left + (right - left) / 2;
    leftResult = findMinMax(arr, left, mid);
    rightResult = findMinMax(arr, mid + 1, right);

    // Combine the results
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;

    return result;
}

int main() {
    int arr[] = {12, 34, 7, 56, 89, 23, 5, 67}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Find minimum and maximum using divide and conquer
    MinMax result = findMinMax(arr, 0, size - 1);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    return 0;
}

