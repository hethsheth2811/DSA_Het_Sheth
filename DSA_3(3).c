#include <stdio.h>
#include <conio.h>

/* Function to swap two numbers using their addresses */
void swap(int *a, int *b)
{
    int temp;

    /* Store the value of first number in temp */
    temp = *a;

    /* Assign the value of second number to first number */
    *a = *b;

    /* Assign the original first value to second number */
    *b = temp;
}

void main()
{
    int num1, num2;

    /* Accept two numbers from the user */
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    /* Display numbers before swapping */
    printf("\nBefore swapping:");
    printf("\nFirst number = %d", num1);
    printf("\nSecond number = %d", num2);

    /* Pass addresses of num1 and num2 to swap function */
    swap(&num1, &num2);

    /* Display numbers after swapping */
    printf("\n\nAfter swapping:");
    printf("\nFirst number = %d", num1);
    printf("\nSecond number = %d", num2);
}
