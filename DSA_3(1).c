#include <stdio.h>
#include <conio.h>

void main() {
    /* 1. ARRAY OF POINTERS
    * An array where each element is a pointer to an integer.
    * Syntax: int *arr_of_ptrs[SIZE];
    * -----------------------------------------------------*/
    int a = 10, b = 20, c = 30;
    int *arr_of_ptrs[3];
    int i;

    /* 2. POINTER TO AN ARRAY
    * A single pointer that points to an entire array of 3 integers.
    * Syntax: int (*ptr_to_arr)[SIZE];
    * -----------------------------------------------------*/
    int numbers[3] = {100, 200, 300};
    int (*ptr_to_arr)[3];
    printf("1. DEMONSTRATING ARRAY OF POINTERS\n");
    arr_of_ptrs[0] = &a;
    arr_of_ptrs[1] = &b;
    arr_of_ptrs[2] = &c;

    for (i = 0; i < 3; i++) {
        printf("Address stored in arr_of_ptrs[%d] = %p, Value = %d\n",
            i, (void*)arr_of_ptrs[i], *arr_of_ptrs[i]);
    }


    printf("\n2. DEMONSTRATING POINTER TO AN ARRAY\n");
    /* Assign the address of the whole array */
    ptr_to_arr = &numbers;

    for (i = 0; i < 3; i++) {
        /* (*ptr_to_arr)[i] dereferences the array pointer, then accesses element i */
        printf("Value at numbers[%d] via ptr_to_arr = %d\n",
            i, (*ptr_to_arr)[i]);
    }
}
