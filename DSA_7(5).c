#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at Beginning */
void insertBeginning(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
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
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

/* Insert after a given node */
void insertAfter(int given, int value)
{
    struct Node *temp;
    struct Node *newNode;

    temp = head;

    while (temp != NULL && temp->data != given)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Given node not found\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

/* Delete from Beginning */
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

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted = %d\n", temp->data);
    free(temp);
}

/* Delete from End */
void deleteEnd()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    printf("Deleted = %d\n", temp->data);
    free(temp);
}

/* Delete a given node */
void deleteMiddle(int value)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted = %d\n", temp->data);
    free(temp);
}

/* Display */
void display()
{
    struct Node *temp;

    temp = head;

    printf("List: ");

    while (temp != NULL)
    {
        printf("%d <=> ", temp->data);
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

    /* 1. Insert at Beginning */
    insertBeginning(5);
    printf("\nAfter inserting 5 at beginning:\n");
    display();

    /* 2. Insert after given node */
    insertAfter(20, 25);
    printf("\nAfter inserting 25 after 20:\n");
    display();

    /* 3. Insert at End */
    insertEnd(40);
    printf("\nAfter inserting 40 at end:\n");
    display();

    /* 4. Delete from Beginning */
    deleteBeginning();
    printf("\nAfter deleting from beginning:\n");
    display();

    /* 5. Delete from End */
    deleteEnd();
    printf("\nAfter deleting from end:\n");
    display();

    /* 6. Delete from Middle */
    deleteMiddle(25);
    printf("\nAfter deleting 25 from middle:\n");
    display();

    getch();
    return 0;
}
