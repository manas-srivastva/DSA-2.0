#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;  // element found
        } 
        else if (arr[mid] < key) {
            low = mid + 1;  // search in right half
        } 
        else {
            high = mid - 1; // search in left half
        }
    }

    return -1; // element not found
}

int main() {
    int arr[100], n, i, key, result;

    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);

    printf("Enter %d elements in ascending order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Call the binary search function
    result = binarySearch(arr, n, key);

    if (result != -1) {
        printf("Element %d found at position %d.\n", key, result + 1);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
