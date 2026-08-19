#include <stdio.h>
#include <conio.h>

// print the array on a single line
void print_array(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

// linear search logic
int linear_search(int arr[], int n, int key) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1; // returns -1 if not found
}

// binary search logic
int binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // returns -1 if not found
}

void main() {
    // static array already sorted
    int arr[] = {9, 47, 65, 77, 93};
    int n = 5;
    int key, res_linear, res_binary;

    printf("Sorted array: ");
    print_array(arr, n);
    printf("\n\n");

    // asking for input so one block handles both found and not found
    printf("Enter element to search: ");
    scanf("%d", &key);
    printf("\n");

    res_linear = linear_search(arr, n, key);
    if(res_linear != -1) {
        printf("Linear search result: found at index %d\n", res_linear);
    } else {
        printf("Linear search result: not found\n");
    }

    res_binary = binary_search(arr, n, key);
    if(res_binary != -1) {
        printf("Binary search result: found at index %d\n", res_binary);
    } else {
        printf("Binary search result: not found\n");
    }
}

