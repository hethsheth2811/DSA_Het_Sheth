#include <stdio.h>
#include <conio.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

/* Check whether Deque is Empty */
void isEmpty()
{
    if (front == -1)
        printf("Deque is Empty\n");
    else
        printf("Deque is Not Empty\n");
}

/* Check whether Deque is Full */
void isFull()
{
    if ((front == 0 && rear == MAX - 1) || front == rear + 1)
        printf("Deque is Full\n");
    else
        printf("Deque is Not Full\n");
}

/* Get Front Item */
void getFront()
{
    if (front == -1)
        printf("Deque is Empty\n");
    else
        printf("Front Item = %d\n", deque[front]);
}

/* Get Rear Item */
void getRear()
{
    if (rear == -1)
        printf("Deque is Empty\n");
    else
        printf("Rear Item = %d\n", deque[rear]);
}

/* Insert at Rear */
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

/* Insert at Front */
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

int main()
{
    insertLast(10);
    insertLast(20);
    insertLast(30);

    getFront();
    getRear();

    isEmpty();
    isFull();

    insertFront(5);

    getFront();
    getRear();

    isEmpty();
    isFull();

    getch();
    return 0;
}
