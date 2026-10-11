/* 
Name: Aswin K U 
Roll No: CS06
Date: 05/08/2026

Experiment No : 4
 
Heading: Linkedlists
 
AIM: Implementation  of  linkedlists  and  operations  on  linkedlists  


ALGORITHM

1. Start.

2. Initialize head = NULL.

3. Create a linked list by allocating memory for each node and reading data from the user.

4. Link each new node to the previous node until the user chooses to stop.

5. Display the linked list and the number of nodes.

6. Display the menu of operations.

7. Read the user's choice.

8. If insertion at beginning is selected, create a new node and link it before the head.

9. If insertion in between is selected, read the position, locate the node and insert the new node.

10. If insertion at end is selected, create a new node and link it to the last node.

11. If deletion at beginning is selected, remove the first node and update the head.

12. If deletion in between is selected, locate the position, unlink the node and free its memory.

13. If deletion at end is selected, locate the last node, unlink it and free its memory.

14. Display the updated linked list after each operation.

15. Repeat steps 6 to 14 until the user selects Quit.

16. Stop.

SOURCE CODE
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head,*newnode,*temp;

void printList(){
    temp = head;
    while(temp != NULL){
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void nodeCreation(){
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the number : ");
    scanf("%d",&newnode->data);

    newnode->next = NULL;
}

int createList(){
    int choice,count = 0;

    do{
        nodeCreation();

        if(head == NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }

        count++;

        printf("\nEnter data again ? (1/0) : ");
        scanf("%d",&choice);

    }while(choice == 1);

    return count;
}

void insertionAtBeginning(){
    nodeCreation();

    newnode->next = head;
    head = newnode;
}

void InsertionInbetween(int count){
    int pos,i;

    printf("\nEnter position you want to insert : ");
    scanf("%d",&pos);

    if(pos == 0){
        insertionAtBeginning();
    }
    else{
        if(pos > count || pos < 0){
            printf("Invalid position\n");
        }
        else{
            temp = head;
            nodeCreation();

            i = 1;

            while(i < pos){
                temp = temp->next;
                i++;
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void insertionAtEnd(){
    nodeCreation();

    if(head == NULL){
        head = newnode;
        return;
    }

    temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
}

void DeletionAtbeginning(){

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}

void Deletioninbetween(int count){
    int pos,i;
    struct node *previous_node;

    printf("\nEnter position you want to delete : ");
    scanf("%d",&pos);

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(pos == 0){
        DeletionAtbeginning();
    }
    else{
        if(pos >= count || pos < 0){
            printf("Invalid position\n");
        }
        else{
            previous_node = head;
            temp = head;

            i = 1;

            while(i <= pos){
                previous_node = temp;
                temp = temp->next;
                i++;
            }

            previous_node->next = temp->next;
            free(temp);
        }
    }
}

void DeletionAtEnd(){

    struct node *previous_node;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while(temp->next != NULL){
        previous_node = temp;
        temp = temp->next;
    }

    previous_node->next = NULL;
    free(temp);
}

int main(){

    int option,n,count;

    head = NULL;

    count = createList();

    printList();

    printf("Number of links : %d",count);

    printf("\nDo you want to do the operation (1/0) : ");
    scanf("%d",&n);

    while(n){

        printf("\nChoose your options : \n");
        printf("1. Insertion at beginning\n");
        printf("2. Insertion inbetween\n");
        printf("3. Insertion at end\n");
        printf("4. Deletion at beginning\n");
        printf("5. Deletion inbetween\n");
        printf("6. Deletion at end\n");
        printf("7. Quit\n");
        printf(": ");

        scanf("%d",&option);

        switch(option){

            case 1:
                insertionAtBeginning();
                count++;
                printList();
                break;

            case 2:
                InsertionInbetween(count);
                count++;
                printList();
                break;

            case 3:
                insertionAtEnd();
                count++;
                printList();
                break;

            case 4:
                if(head != NULL){
                    DeletionAtbeginning();
                    count--;
                }
                printList();
                break;

            case 5:
                if(head != NULL){
                    Deletioninbetween(count);
                    count--;
                }
                printList();
                break;

            case 6:
                if(head != NULL){
                    DeletionAtEnd();
                    count--;
                }
                printList();
                break;

            case 7:
                n = 0;
                break;

            default:
                printf("\nInvalid option\n");
                break;
        }
    }

    return 0;
}

/*
OUTPUT

Enter the number : 10

Enter data again ? (1/0) : 1
Enter the number : 20

Enter data again ? (1/0) : 1
Enter the number : 30

Enter data again ? (1/0) : 0

10-> 20-> 30-> NULL
Number of links : 3
Do you want to do the operation (1/0) : 1

Choose your options :
1. Insertion at beginning
2. Insertion inbetween
3. Insertion at end
4. Deletion at beginning
5. Deletion inbetween
6. Deletion at end
7. Quit
: 1

Enter the number : 5
5-> 10-> 20-> 30-> NULL

Choose your options :
1. Insertion at beginning
2. Insertion inbetween
3. Insertion at end
4. Deletion at beginning
5. Deletion inbetween
6. Deletion at end
7. Quit
: 2

Enter position you want to insert : 2
Enter the number : 15
5-> 10-> 15-> 20-> 30-> NULL

Choose your options :
1. Insertion at beginning
2. Insertion inbetween
3. Insertion at end
4. Deletion at beginning
5. Deletion inbetween
6. Deletion at end
7. Quit
: 3

Enter the number : 40
5-> 10-> 15-> 20-> 30-> 40-> NULL

Choose your options :
1. Insertion at beginning
2. Insertion inbetween
3. Insertion at end
4. Deletion at beginning
5. Deletion inbetween
6. Deletion at end
7. Quit
: 4

10-> 15-> 20-> 30-> 40-> NULL

Choose your options :
1. Insertion at beginning
2. Insertion inbetween
3. Insertion at end
4. Deletion at beginning
5. Deletion inbetween
6. Deletion at end
7. Quit
: 5

Enter position you want to delete : 2
10-> 15-> 30-> 40-> NULL

Choose your options :
1. Insertion at beginning
2. Insertion inbetween
3. Insertion at end
4. Deletion at beginning
5. Deletion inbetween
6. Deletion at end
7. Quit
: 6

10-> 15-> 30-> NULL

Choose your options :
1. Insertion at beginning
2. Insertion inbetween
3. Insertion at end
4. Deletion at beginning
5. Deletion inbetween
6. Deletion at end
7. Quit
: 7
*/