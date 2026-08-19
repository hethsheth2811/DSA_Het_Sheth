#include <stdio.h>
#include <conio.h>

void main() {
    int a[8], i;
    int max1, max2, min1, min2;

    printf("Enter 8 elements:\n");
    for(i = 0; i < 8; i++) {
        scanf("%d", &a[i]);
    }

    // setting initial values
    max1 = a[0];
    min1 = a[0];
    max2 = -32768;
    min2 = 32767;

    for(i = 0; i < 8; i++) {
        // finding max and second max
        if(a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if(a[i] > max2 && a[i] < max1) {
            max2 = a[i];
        }

        // finding min and second min
        if(a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        } else if(a[i] < min2 && a[i] > min1) {
            min2 = a[i];
        }
    }

    printf("\nMaximum: %d\n", max1);
    printf("Second maximum: %d\n", max2);
    printf("Minimum: %d\n", min1);
    printf("Second minimum: %d\n", min2);
}
