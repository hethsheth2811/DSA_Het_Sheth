#include <stdio.h>
#include <conio.h>

/* Define the structure for Employee */
struct Employee {
    int emp_id;
    char emp_name[50];
    float emp_salary;
};

/* Define the structure for Organization containing nested Employee array */
struct Organization {
    int org_id;
    char org_name[50];
    struct Employee emp[2]; /* Array of 2 employees nested inside Organization */
};

void main() {
    struct Organization org[2]; /* Array to hold 2 organizations */
    int i, j;

    /* Input details for 2 Organizations and 2 Employees per Organization */
    for (i = 0; i < 2; i++) {
        printf("--- Enter Details for Organization %d ---\n", i + 1);

        printf("Enter Organization ID: ");
        scanf("%d", &org[i].org_id);

        printf("Enter Organization Name: ");
        scanf("%s", org[i].org_name);

        for (j = 0; j < 2; j++) {
            printf("\n  Enter Details for Employee %d in %s:\n", j + 1, org[i].org_name);

            printf("  Enter Employee ID: ");
            scanf("%d", &org[i].emp[j].emp_id);

            printf("  Enter Employee Name: ");
            scanf("%s", org[i].emp[j].emp_name);

            printf("  Enter Employee Salary: ");
            scanf("%f", &org[i].emp[j].emp_salary);
        }
        printf("\n");
    }

    /* Output the details */
    printf("================ DISPLAYING DETAILS ================\n\n");

    for (i = 0; i < 2; i++) {
        printf("Organization ID   : %d\n", org[i].org_id);
        printf("Organization Name : %s\n", org[i].org_name);
        printf("----------------------------------------------------\n");
        printf("  Emp ID\tEmp Name\tSalary\n");
        printf("----------------------------------------------------\n");

        for (j = 0; j < 2; j++) {
            printf("  %d\t\t%s\t\t%.2f\n",
                   org[i].emp[j].emp_id,
                   org[i].emp[j].emp_name,
                   org[i].emp[j].emp_salary);
        }
        printf("====================================================\n\n");
    }
}
