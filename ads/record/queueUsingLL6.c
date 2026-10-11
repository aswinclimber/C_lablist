/* 
Name: Aswin K U 
Roll No: CS06
Date: 14/08/2026

Experiment No : 6
 
Heading:  Queue  using  linkedlist
 
AIM: Implementation  of  queue  using  linkedlist


ALGORITHM

1. Start.

2. Initialize front = NULL and rear = NULL.

3. Display the menu with Enqueue, Dequeue, Peek, Display and Exit options.

4. Read the user's choice.

5. If Enqueue is selected, create a new node, read the value and insert it at the rear of the queue.

6. If Dequeue is selected, check whether the queue is empty.
   If empty, display Underflow.
   Otherwise, remove the front node and free its memory.

7. If Peek is selected, check whether the queue is empty.
   If empty, display Queue is empty.
   Otherwise, display the front element.

8. If Display is selected, traverse the queue from front to rear and display all elements.

9. Repeat steps 3 to 8 until the user selects Exit.

10. Stop.

SOURCE CODE
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int value){

    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the value to enqueue : ");
    scanf("%d",&value);

    newnode->data = value;
    newnode->next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){

    struct node *temp;

    if(front == NULL && rear == NULL){
        printf("Underflow");
    }
    else if(front == rear){
        temp = front;
        front = rear = NULL;
        free(temp);
    }
    else{
        temp = front;
        front = front->next;
        free(temp);
    }
}

void peek(){

    if(front == NULL && rear == NULL){
        printf("Queue is empty");
    }
    else{
        printf("Front element : %d",front->data);
    }
}

void display(){

    struct node *temp;

    if(front == NULL && rear == NULL){
        printf("Queue is empty");
    }
    else{
        temp = front;

        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

int main(){

    int n = 1, option, value;

    while(n){

        printf("\nSelect the operation you want to perform :\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        scanf("%d",&option);

        switch(option){

            case 1:
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                n = 0;
                break;

            default:
                printf("Invalid option");
        }
    }

    return 0;
}

/*
OUTPUT

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
1
Enter the value to enqueue : 10

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
1
Enter the value to enqueue : 20

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
1
Enter the value to enqueue : 30

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
4
10 20 30

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
3
Front element : 10

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
2

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
4
20 30

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
3
Front element : 20

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
2

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
2

Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
2
Underflow
Select the operation you want to perform :
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
5
*/