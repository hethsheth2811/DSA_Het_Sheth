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

/* Insert After a Given Node */
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
int deleteBeginning()
{
    struct Node *temp;
    int value;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return -1;
    }

    temp = head;
    value = temp->data;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    return value;
}

/* Delete from End */
int deleteEnd()
{
    struct Node *temp;
    int value;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return -1;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    value = temp->data;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);

    return value;
}

/* Delete from Middle */
int deleteMiddle(int value)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return -1;
    }

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node not found\n");
        return -1;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    return value;
}

/* Display List */
void display()
{
    struct Node *temp;

    temp = head;

    printf("List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int deleted;

    /* Creating initial list */
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    printf("Original List:\n");
    display();

    /* Insert at Beginning */
    insertBeginning(5);
    printf("\nAfter inserting 5 at beginning:\n");
    display();

    /* Insert after given node */
    insertAfter(20, 25);
    printf("\nAfter inserting 25 after 20:\n");
    display();

    /* Insert at End */
    insertEnd(40);
    printf("\nAfter inserting 40 at end:\n");
    display();

    /* Delete from Beginning */
    deleted = deleteBeginning();
    printf("\nAfter deleting from beginning:\n");
    printf("Deleted = %d\n", deleted);
    display();

    /* Delete from End */
    deleted = deleteEnd();
    printf("\nAfter deleting from end:\n");
    printf("Deleted = %d\n", deleted);
    display();

    /* Delete from Middle */
    deleted = deleteMiddle(25);
    printf("\nAfter deleting 25 from middle:\n");
    printf("Deleted = %d\n", deleted);
    display();

    getch();
    return 0;
}
