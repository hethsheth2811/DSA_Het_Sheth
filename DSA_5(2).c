#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Function to push an operator into the stack */
void push(char ch)
{
    stack[++top] = ch;
}

/* Function to pop an operator from the stack */
char pop()
{
    return stack[top--];
}

/* Function to return the precedence of an operator */
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

/* Function to convert infix expression into postfix */
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    top = -1;   /* Initialize stack */

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        /* If the character is an operand, add it directly to postfix */
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        /* Opening bracket is pushed into the stack */
        else if (ch == '(')
        {
            push(ch);
        }

        /* When closing bracket is found, pop until '(' is found */
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            /* Remove '(' from the stack */
            if (top != -1)
                pop();
        }

        /* If the character is an operator */
        else
        {
            /*
             * Pop operators having higher or equal precedence.
             * For '^', right associativity is maintained.
             */
            while (top != -1 &&
                   stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) && ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    /* Pop all remaining operators from the stack */
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix expression: %s", postfix);
}
