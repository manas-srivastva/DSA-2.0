#include <stdio.h>

int main() {
    int arr[50], n;
    int i, j, minIndex, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection Sort logic
    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap elements
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    // Printing sorted array
    printf("Sorted array using Selection Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
