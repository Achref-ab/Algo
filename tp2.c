#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

float average(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return n ? (float)sum / n : 0.0f;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int *arr = malloc(sizeof(int) * n);
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    int largest = arr[0];
    for (int i = 1; i < n; i++)
        largest = max(largest, arr[i]);

    float avg = average(arr, n);

    printf("\nLargest number = %d\n", largest);
    printf("Average = %.2f\n", avg);

    free(arr);
    return 0;
}
