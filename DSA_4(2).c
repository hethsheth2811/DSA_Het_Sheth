#include <stdio.h>
#include <conio.h>

#define MAX 10

int stack[MAX];
int top_index = -1;

/* Check whether stack is empty */
int isEmpty()
{
    if (top_index == -1)
        return 1;
    else
        return 0;
}

/* Push element into stack */
void push(int x)
{
    if (top_index == MAX - 1)
    {
        printf("\nStack Overflow");
        return;
    }

    top_index++;
    stack[top_index] = x;
}

/* Pop element from stack */
int pop()
{
    int x;

    if (isEmpty())
    {
        return -1;
    }

    x = stack[top_index];
    top_index--;

    return x;
}

/* Return top element */
int top()
{
    if (isEmpty())
        return -1;

    return stack[top_index];
}

/* Insert element at correct position */
void insertSorted(int x)
{
    int temp;

    if (isEmpty() || top() <= x)
    {
        push(x);
        return;
    }

    temp = pop();

    insertSorted(x);

    push(temp);
}

/* Sort stack using recursion */
void sortStack()
{
    int x;

    if (isEmpty())
        return;

    x = pop();

    sortStack();

    insertSorted(x);
}

/* Display stack using recursion */
void display()
{
    int x;

    if (isEmpty())
        return;

    x = pop();

    printf("%d ", x);

    display();

    push(x);
}

void main()
{
    push(30);
    push(10);
    push(50);
    push(20);
    push(40);

    printf("Original Stack:\n");
    display();

    sortStack();

    printf("\n\nSorted Stack:\n");
    display();
}
