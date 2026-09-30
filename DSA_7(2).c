#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at End - to create the list */
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

/* a. Delete from Beginning */
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted = %d\n", temp->data);
    free(temp);
}

/* b. Delete from End */
void deleteEnd()
{
    struct Node *temp;
    struct Node *prev;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("Deleted = %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted = %d\n", temp->data);
    free(temp);
}

/* c. Delete from Middle */
void deleteMiddle(int value)
{
    struct Node *temp;
    struct Node *prev;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    /* If first node contains the value */
    if (head->data == value)
    {
        temp = head;
        head = head->next;

        printf("Deleted = %d\n", temp->data);
        free(temp);
        return;
    }

    temp = head;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    prev->next = temp->next;

    printf("Deleted = %d\n", temp->data);
    free(temp);
}

/* Display List */
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
    /* Creating List */
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    printf("Original List:\n");
    display();

    /* a. Delete from Beginning */
    deleteBeginning();
    display();

    /* b. Delete from End */
    deleteEnd();
    display();

    /* c. Delete from Middle */
    deleteMiddle(30);
    display();

    getch();
    return 0;
}
