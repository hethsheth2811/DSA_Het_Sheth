#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

/* Function to insert an element into the stack */
void push(int x)
{
    stack[++top] = x;
}

/* Function to remove and return the top element */
int pop()
{
    return stack[top--];
}

/* Function to evaluate a postfix expression */
int evaluate(char postfix[])
{
    int i, a, b;

    top = -1;   /* Initialize stack */

    for (i = 0; postfix[i] != '\0'; i++)
    {
        /* If the character is a digit, push it into the stack */
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }

        /* Ignore blank spaces */
        else if (postfix[i] == ' ')
        {
            continue;
        }

        /* If it is an operator, perform the required operation */
        else
        {
            b = pop();  /* Second operand */
            a = pop();  /* First operand */

            switch (postfix[i])
            {
                case '+':
                    push(a + b);
                    break;

                case '-':
                    push(a - b);
                    break;

                case '*':
                    push(a * b);
                    break;

                case '/':
                    push(a / b);
                    break;
            }
        }
    }

    /* Final value remaining in the stack is the answer */
    return pop();
}

void main()
{
    char exp1[] = "2 3 1 * + 9 -";
    char exp2[] = "2 2 + 2 / 5 * 7 +";

    printf("Postfix Expression 1: %s", exp1);
    printf("\nResult = %d", evaluate(exp1));

    printf("\n\nPostfix Expression 2: %s", exp2);
    printf("\nResult = %d", evaluate(exp2));
}
