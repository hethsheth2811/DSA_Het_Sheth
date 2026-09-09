#include <stdio.h>
#include <conio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Check whether queue is full */
int isFull()
{
    if ((rear + 1) % MAX == front)
        return 1;
    else
        return 0;
}

/* Check whether queue is empty */
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

/* Insert an element into circular queue */
void enqueue()
{
    int value;

    if (isFull())
    {
        printf("\nQueue is Full!");
        return;
    }

    printf("\nEnter element to insert: ");
    scanf("%d", &value);

    /* First element */
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

    printf("\n%d inserted into queue.", value);
}

/* Delete an element from circular queue */
void dequeue()
{
    int value;

    if (isEmpty())
    {
        printf("\nQueue is Empty!");
        return;
    }

    value = queue[front];

    /* If only one element is present */
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("\n%d deleted from queue.", value);
}

/* Display front element */
void displayFront()
{
    if (isEmpty())
        printf("\nQueue is Empty!");
    else
        printf("\nFront element = %d", queue[front]);
}

/* Display rear element */
void displayRear()
{
    if (isEmpty())
        printf("\nQueue is Empty!");
    else
        printf("\nRear element = %d", queue[rear]);
}

/* Display complete queue */
void display()
{
    int i;

    if (isEmpty())
    {
        printf("\nQueue is Empty!");
        return;
    }

    printf("\nQueue elements are: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

void main()
{
    int choice;

    while (1)
    {
        printf("===== CIRCULAR QUEUE =====");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Check isFull");
        printf("\n4. Check isEmpty");
        printf("\n5. Front");
        printf("\n6. Rear");
        printf("\n7. Display Queue");
        printf("\n8. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                if (isFull())
                    printf("\nQueue is Full!");
                else
                    printf("\nQueue is Not Full.");
                break;

            case 4:
                if (isEmpty())
                    printf("\nQueue is Empty!");
                else
                    printf("\nQueue is Not Empty.");
                break;

            case 5:
                displayFront();
                break;

            case 6:
                displayRear();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("\nExiting...");
                getch();
                return;

            default:
                printf("\nInvalid choice!");
        }

        getch();
    }
}
