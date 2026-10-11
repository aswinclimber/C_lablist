/* 
Name: Aswin K U 
Roll No: CS06
Date: 21/09/2026

Experiment No : 13
 
Heading: Infix to Postfix using stacks
 
AIM: Conversion  of  an  infix  expression  to  the  postfix  form  using  stacks


ALGORITHM

1. Start.

2. Declare the stack and initialize top = -1.

3. Read the infix expression.

4. Scan the infix expression from left to right.

5. If the character is an operand, add it to the postfix expression.

6. If the character is '(', push it onto the stack.

7. If the character is ')', pop operators from the stack and add them to the postfix expression until '(' is found. Remove '(' from the stack.

8. If the character is an operator:

   a. Pop operators with higher precedence from the stack and add them to the postfix expression.

   b. If the precedence is equal, pop the operator unless the current operator is '^'.

   c. Push the current operator onto the stack.

9. Repeat steps 5 to 8 until the entire infix expression is scanned.

10. Pop all remaining operators from the stack and add them to the postfix expression.

11. Add the null character '\0' at the end of the postfix expression.

12. Display the postfix expression.

13. Stop.


SOURCE CODE
*/
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

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

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;

        else if (ch == '(')
            push(ch);

        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) && ch != '^')))
                postfix[j++] = pop();

            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


/*
OUTPUT

Enter the infix expression: (A+B)*C-D/E

Postfix expression: AB+C*DE/-

*/