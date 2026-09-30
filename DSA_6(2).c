#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

/* a. Check if Queue is Empty */
void isEmpty()
{
    if (front == NULL)
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");
}

/* b. Check if Queue is Full */
void isFull()
{
    struct Node *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL)
        printf("Queue is Full\n");
    else
    {
        printf("Queue is Not Full\n");
        free(temp);
    }
}

/* c. Insert element into Queue */
void enqueue(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Queue is Full\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted\n", value);
}

/* d. Delete element from Queue */
void dequeue()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;

    printf("%d deleted\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

/* e. Print Front element */
void getFront()
{
    if (front == NULL)
        printf("Queue is Empty\n");
    else
        printf("Front = %d\n", front->data);
}

/* Print Rear element */
void getRear()
{
    if (rear == NULL)
        printf("Queue is Empty\n");
    else
        printf("Rear = %d\n", rear->data);
}

/* Display Queue */
void display()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;

    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    getFront();
    getRear();

    isEmpty();
    isFull();

    dequeue();

    display();

    getFront();
    getRear();

    isEmpty();
    isFull();

    getch();
    return 0;
}
