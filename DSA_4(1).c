#include <stdio.h>
#include <conio.h>

#define MAX 5

int stack[MAX];
int top = -1;

/* Check whether stack is empty */
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

/* Check whether stack is full */
int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

/* Insert element into stack */
void push(int value)
{
    if (isFull())
    {
        printf("\nStack Overflow!");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("\n%d pushed into stack.", value);
    }
}

/* Delete element from stack */
void pop()
{
    if (isEmpty())
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\n%d popped from stack.", stack[top]);
        top--;
    }
}

/* Print topmost element */
void print_top()
{
    if (isEmpty())
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\nTop element = %d", stack[top]);
    }
}

void main()
{
    int choice, value;
    while (1)
    {
        printf("\n\n----- STACK MENU -----");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print Top");
        printf("\n4. Check Empty");
        printf("\n5. Check Full");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                print_top();
                break;

            case 4:
                if (isEmpty())
                    printf("\nStack is Empty.");
                else
                    printf("\nStack is Not Empty.");
                break;

            case 5:
                if (isFull())
                    printf("\nStack is Full.");
                else
                    printf("\nStack is Not Full.");
                break;

            case 6:
                printf("\nExiting...");
                getch();
                return;

            default:
                printf("\nInvalid choice!");
        }
    }
}
