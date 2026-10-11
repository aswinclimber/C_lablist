/* 
Name: Aswin K U 
Roll No: CS06
Date: 25/07/2026

Experiment No : 2
 
Heading: Queues  using  arrays
 
AIM: Implementation  of  queues  using  arrays


ALGORITHM

1. Start.

2. Initialize `front = -1` and `rear = -1`.

3. Read the size of the queue and create the queue array.

4. Display the menu and read the user's choice.

5. For Enqueue:
   - Check if `rear == size - 1`.
   - If true, display Overflow, queue is full.
   - If the queue is empty, set `front = rear = 0` and insert the value.
   - Otherwise, increment `rear` and insert the value.

6. For Dequeue:
   - Check if the queue is empty.
   - If empty, display Underflow.
   - If `front == rear`, set `front = rear = -1`.
   - Otherwise, increment `front`.

7. For Peek:
   - Check if the queue is empty.
   - If empty, display Queue is empty.
   - Otherwise, display the value at `queue[front]`.

8. For Display:
   - Check if the queue is empty.
   - If empty, display Queue is empty.
   - Otherwise, display all elements from `front` to `rear`.

9. For Exit, terminate the program.

10. For an invalid option, display Invalid option.

11. Repeat the operations until Exit is selected.

12. Stop.


SOURCE CODE
*/
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

/*
OUTPUT

Enter the size of queue : 3

select the operation you want to perform :
1. enqueue
2. dequeue
3. peek
4. display
5. exit
1
Enter the value to enqueue : 10

select the operation you want to perform :
1. enqueue
2. dequeue
3. peek
4. display
5. exit
1
Enter the value to enqueue : 20

select the operation you want to perform :
1. enqueue
2. dequeue
3. peek
4. display
5. exit
1
Enter the value to enqueue : 30

select the operation you want to perform :
1. enqueue
2. dequeue
3. peek
4. display
5. exit
4
102030

select the operation you want to perform :
1. enqueue
2. dequeue
3. peek
4. display
5. exit
3
10

select the operation you want to perform :
1. enqueue
2. dequeue
3. peek
4. display
5. exit
2

select the operation you want to perform :
1. enqueue
2. dequeue
3. peek
4. display
5. exit
4
2030

select the operation you want to perform :
1. enqueue
2. dequeue
3. peek
4. display
5. exit
5

*/