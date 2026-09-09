#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Structure for a queue node */
struct node
{
    int data;
    struct node *next;
};

/* Front and rear pointers */
struct node *front = NULL;
struct node *rear = NULL;

/* Check whether queue is empty */
int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

/* Insert element into queue */
void enqueue()
{
    int value;
    struct node *newnode;

    printf("\nEnter element to insert: ");
    scanf("%d", &value);

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    newnode->data = value;
    newnode->next = NULL;

    /* If queue is empty */
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("\n%d inserted into queue.", value);
}

/* Delete element from queue */
void dequeue()
{
    struct node *temp;
    int value;

    if (isEmpty())
    {
        printf("\nQueue is Empty!");
        return;
    }

    temp = front;
    value = temp->data;

    front = front->next;

    /* If queue becomes empty */
    if (front == NULL)
        rear = NULL;

    free(temp);

    printf("\n%d deleted from queue.", value);
}

/* Display front element */
void displayFront()
{
    if (isEmpty())
        printf("\nQueue is Empty!");
    else
        printf("\nFront element = %d", front->data);
}

/* Display rear element */
void displayRear()
{
    if (isEmpty())
        printf("\nQueue is Empty!");
    else
        printf("\nRear element = %d", rear->data);
}

/* Display all queue elements */
void display()
{
    struct node *temp;

    if (isEmpty())
    {
        printf("\nQueue is Empty!");
        return;
    }

    temp = front;

    printf("\nQueue elements are: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Main function */
void main()
{
    int choice;

    while (1)
    {
        printf("===== QUEUE USING LINKED LIST =====");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Check isEmpty");
        printf("\n4. Front");
        printf("\n5. Rear");
        printf("\n6. Display Queue");
        printf("\n7. Exit");

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
                if (isEmpty())
                    printf("\nQueue is Empty!");
                else
                    printf("\nQueue is Not Empty.");
                break;

            case 4:
                displayFront();
                break;

            case 5:
                displayRear();
                break;

            case 6:
                display();
                break;

            case 7:
                printf("\nExiting...");
                getch();
                return;

            default:
                printf("\nInvalid choice!");
        }

        getch();
    }
}
