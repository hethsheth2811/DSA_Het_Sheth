#include <stdio.h>
#include <conio.h>

/* Define a structure for Student details */
struct Student {
    int id;
    char name[20];
    float marks;
};

void main() {
    /* Declare a structure variable */
    struct Student s1 = {101, "Het", 88.5};

    /* Declare a pointer to the structure */
    struct Student *ptr;

    /* Assign address of s1 to pointer */
    ptr = &s1;

    printf("=== ACCESSING STRUCTURE VIA POINTER (-> OPERATOR) ===\n");
    printf("ID   : %d\n", ptr->id);
    printf("Name : %s\n", ptr->name);
    printf("Marks: %.2f\n\n", ptr->marks);

    /* Modifying values using the arrow operator */
    ptr->marks = 92.0;

    printf("=== AFTER MODIFYING MARKS VIA POINTER ===\n");
    printf("Updated Marks: %.2f\n", ptr->marks);
}
