#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

/* Insert at end */
struct Node* insertEnd(struct Node *head, int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(value);

    if (head == NULL)
        return newNode;

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

/* Merge two sorted lists */
struct Node* merge(struct Node *A, struct Node *B)
{
    struct Node *result = NULL;
    struct Node *temp;

    while (A != NULL && B != NULL)
    {
        if (A->data <= B->data)
        {
            result = insertEnd(result, A->data);
            A = A->next;
        }
        else
        {
            result = insertEnd(result, B->data);
            B = B->next;
        }
    }

    while (A != NULL)
    {
        result = insertEnd(result, A->data);
        A = A->next;
    }

    while (B != NULL)
    {
        result = insertEnd(result, B->data);
        B = B->next;
    }

    return result;
}

/* Display list */
void display(struct Node *head)
{
    struct Node *temp;

    temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" => ");

        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Node *A = NULL;
    struct Node *B = NULL;
    struct Node *C;

    /* First sorted list */
    A = insertEnd(A, 5);
    A = insertEnd(A, 10);
    A = insertEnd(A, 15);

    /* Second sorted list */
    B = insertEnd(B, 2);
    B = insertEnd(B, 3);
    B = insertEnd(B, 20);

    printf("List A: ");
    display(A);

    printf("List B: ");
    display(B);

    C = merge(A, B);

    printf("Merged List: ");
    display(C);

    getch();
    return 0;
}
