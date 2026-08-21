#include <stdio.h>
#include <conio.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Function to push a bracket into the stack */
void push(char ch)
{
    stack[++top] = ch;
}

/* Function to pop a bracket from the stack */
char pop()
{
    return stack[top--];
}

/* Function to check whether brackets are balanced */
int isBalanced(char exp[])
{
    int i;
    char ch, open;

    top = -1;   /* Initialize stack */

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        /* Push opening brackets into the stack */
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }

        /* Check closing brackets */
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            /* If stack is empty, there is no matching opening bracket */
            if (top == -1)
                return 0;

            open = pop();

            /* Check whether the opening and closing brackets match */
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{'))
            {
                return 0;
            }
        }
    }

    /* Stack must be empty for the expression to be balanced */
    if (top == -1)
        return 1;
    else
        return 0;
}

void main()
{
    char exp[MAX];

    printf("Enter expression: ");
    gets(exp);

    if (isBalanced(exp))
        printf("\nOutput: Balanced");
    else
        printf("\nOutput: Not Balanced");
}
