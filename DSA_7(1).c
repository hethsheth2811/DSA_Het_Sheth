#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at Front */
void insertFront(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

/* Insert After a Given Node */
void insertAfter(int given, int value)
{
    struct Node *newNode;
    struct Node *temp;

    temp = head;

    while (temp != NULL && temp->data != given)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Given node not found\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

/* Insert at End */
void insertEnd(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

/* Display Linked List */
void display()
{
    struct Node *temp;

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    /* Creating initial list */
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    printf("Original List:\n");
    display();

    /* a. Insert at Front */
    insertFront(5);
    printf("\nAfter inserting 5 at Front:\n");
    display();

    /* b. Insert after given node */
    insertAfter(20, 25);
    printf("\nAfter inserting 25 after 20:\n");
    display();

    /* c. Insert at End */
    insertEnd(40);
    printf("\nAfter inserting 40 at End:\n");
    display();

    getch();
    return 0;
}
