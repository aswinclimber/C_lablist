#include <stdio.h>

int size,front = -1,rear = -1;

void enqueue(int *queue,int size,int value){
    if (rear == size-1){
        printf("overflow, queue is full");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = value;
    }
    else{
        rear++;
        queue[rear] = value;    
    }
}

void dequeue(int *queue,int size){
    if(front == -1 && rear == -1){
        printf("Underflow");
    }
    else if(front == rear){
        front=rear=-1;
    }
    else{
        front++;
    }
    
}

void peek(int *queue){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        printf("%d",queue[front]);
    }
}

void display(int *queue){
    int i;
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("%d",queue[i]);
        }
    }
}

int main(){
    printf("Enter the size of queue : ");
    scanf("%d",&size);
    int queue[size],value;
    int n = 1,option;
    while(n){
        printf("\nselect the operation you want to perform : \n1. enqueue \n2. dequeue \n3. peek \n4. display \n5. exit");
        scanf("%d",&option);
        switch(option){
            case 1:
                    printf("Enter the value to enqueue : ");
                    scanf("%d",&value);
                    enqueue(queue,size,value);
                    break;
            case 2:
                    dequeue(queue,size);
                    break;
            case 3:
                    peek(queue);
                    break;
            case 4:
                    display(queue);
                    break;
            case 5:
                    n = 0;
                    break;
            default:
                    printf("invalid option");
        }
    }
    return 0;
}