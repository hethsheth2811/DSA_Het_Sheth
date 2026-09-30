#include <stdio.h>
#include <conio.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int item)
{
    if ((front == 0 && rear == MAX - 1) || front == rear + 1)
    {
        printf("Deque is Full\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;

    deque[front] = item;
}

void insertLast(int item)
{
    if ((front == 0 && rear == MAX - 1) || front == rear + 1)
    {
        printf("Deque is Full\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    deque[rear] = item;
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted from Front = %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void deleteLast()
{
    if (front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted from Rear = %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque: ");

    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    insertLast(10);
    insertLast(20);
    insertFront(5);
    insertFront(2);

    display();

    deleteFront();
    display();

    deleteLast();
    display();

    getch();
    return 0;
}
