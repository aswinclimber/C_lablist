#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char ch;
    struct Node *next;
};

struct Node* createNode(char ch)
{
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->ch = ch;
    newNode->next = NULL;

    return newNode;
}

void appendNode(struct Node** head, struct Node** tail, char ch)
{
    struct Node* newNode = createNode(ch);

    if(*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void freeList(struct Node* head)
{
    struct Node* temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void processISBN(const char* input)
{
    int len = strlen(input);
    int i;
    int sum = 0;
    int digit;
    int checkDigit;

    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* temp;

    if(len != 9)
    {
        printf("Error: Enter exactly 9 digits.\n");
        return;
    }

    for(i = 0; i < len; i++)
    {
        if(!isdigit(input[i]))
        {
            printf("Error: input must contain digits only.\n");
            return;
        }

        appendNode(&head, &tail, input[i]);
    }

    /*
       ISBN-10:
       10*d1 + 9*d2 + 8*d3 + ... + 2*d9 + check = multiple of 11
    */

    temp = head;

    for(i = 10; i >= 2; i--)
    {
        digit = temp->ch - '0';
        sum += digit * i;
        temp = temp->next;
    }

    checkDigit = (11 - (sum % 11)) % 11;

    printf("\nISBN-10: %s%d\n", input, checkDigit);

    printf("Linked List: ");

    temp = head;

    while(temp != NULL)
    {
        printf("%c -> ", temp->ch);
        temp = temp->next;
    }

    printf("%d -> NULL\n", checkDigit);

    freeList(head);
}

int main()
{
    char input[20];

    printf("Enter first 9 digits of ISBN: ");
    scanf("%s", input);

    processISBN(input);

    return 0;
}