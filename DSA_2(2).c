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
    struct Student s[5]; // Array of structures to store details for 5 students
    int i;

    // Loop to input details for each student
    for(i=0; i<5; i++)
    {
        printf("\nEnter details of student %d\n", i+1);

        printf("Enter name: ");
        gets(s[i].name); // Reads student's name

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll); // Reads student's roll number

        getchar(); //clear the leftover newline

        printf("Enter address: ");
        gets(s[i].address); // Reads student's address
    }

    // Loop to display the details of all students
    printf("\nStudent Details\n");
    for(i=0; i<5; i++)
    {
        printf("\nStudent %d\n", i+1);
        printf("Name = %s\n", s[i].name);
        printf("Roll No. = %d\n", s[i].roll);
        printf("Address = %s\n", s[i].address);
    }
}
