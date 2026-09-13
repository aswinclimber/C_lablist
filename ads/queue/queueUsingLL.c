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