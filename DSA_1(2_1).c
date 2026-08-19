#include <stdio.h>
#include <conio.h>

void main()
{
    int a[50], n, i, j, key;

    // Input array size
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Insertion Sort Algorithm
    for(i = 1; i < n; i++)
    {
        key = a[i]; // Element to be inserted
        j = i - 1;

        // Shift elements greater than key to one position ahead
        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; // Place key at its correct position
    }

    // Display sorted array
    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
