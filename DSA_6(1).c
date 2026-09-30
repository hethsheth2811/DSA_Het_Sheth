#include <stdio.h>
#include <conio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* a. Check if Queue is Full */
void isFull()
{
    if ((rear + 1) % MAX == front)
        printf("Queue is Full\n");
    else
        printf("Queue is Not Full\n");
}

/* b. Check if Queue is Empty */
void isEmpty()
{
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");
}

/* c. Insert element */
void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted\n", value);
}

/* d. Delete element */
void dequeue()
{
    int value;

    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    value = queue[front];
    printf("%d deleted\n", value);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

/* e. Print Front element */
void getFront()
{
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Front = %d\n", queue[front]);
}

/* Print Rear element */
void getRear()
{
    if (rear == -1)
        printf("Queue is Empty\n");
    else
        printf("Rear = %d\n", queue[rear]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    getFront();
    getRear();

    isEmpty();
    isFull();

    dequeue();
    dequeue();

    getFront();
    getRear();

    enqueue(50);
    enqueue(60);

    getFront();
    getRear();

    isEmpty();
    isFull();

    getch();
    return 0;
}
