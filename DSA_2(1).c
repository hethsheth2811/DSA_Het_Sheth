#include<stdio.h>
#include<conio.h>

// Define a structure to hold student details
struct Student
{
    char name[30];
    int roll;
    char address[50];
};

void main()
{
    // Declare a structure variable of type Student
    struct Student s;

    // Input student details
    printf("Enter student name: ");
    gets(s.name);

    printf("Enter roll number: ");
    scanf("%d",&s.roll);

    getchar(); // clear the leftover newline

    printf("Enter address: ");
    gets(s.address);

    // Display student details
    printf("\nStudent Details\n");
    printf("Name = %s\n",s.name);
    printf("Roll No. = %d\n",s.roll);
    printf("Address = %s",s.address);
}
