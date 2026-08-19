#include <stdio.h>
#include <conio.h>

// print function
void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// bubble sort logic
void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// selection sort logic
void selectionSort(int a[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

void main() {
    int a1[100], a2[100];
    int n, i;

    // take array size from user
    printf("Enter array size: ");
    scanf("%d", &n);

    // take array elements from user
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
        a2[i] = a1[i]; // copy for selection sort
    }

    // perform bubble sort
    bubbleSort(a1, n);
    printf("\nArray sorted using bubble sort:\n");
    printArray(a1, n);

    // perform selection sort
    selectionSort(a2, n);
    printf("\nArray sorted using selection sort:\n");
    printArray(a2, n);
}
