#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value){
	if ((rear + 1) % SIZE == front){
		printf("Queue is full\n");
	}
	else{
		if (front == -1){
			front =0;
		}
		rear = (rear + 1) % SIZE;
		queue[rear]  = value;
	}
}



void dequeue(){
	if (front == -1){
		printf("Queue is empty\n");
	}
	else{
		if (front == rear){
			front = rear = -1;
		}
		else{
			front = (front + 1) % SIZE;
		}
	}
}

void display(){
	int i;
	if (front == -1){
		printf("Queue is empty\n");
	}
	else{
		printf("Queue elements : ");
		i = front;

		while(1){
			printf("&d ",queue[i]);

			if (i == rear){
				break;
			}

			i = (i+1) % SIZE;
		}
		printf("\n");
	}
}

int main(){
	int choice, value;

	while(1){
		printf("\n1. Enqueue");
		printf("\n1. Dequeue");
		printf("\n1. Display");
		printf("\n1. Exit");

		printf("\n Enter your choice : ");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				printf("Enter value : ");
				scanf("%d", &value);
				enqueue(value);
				break;

			case 2:
				dequeue();
				break;

			case 3:
				display();
				break;
			case 4:
				return 0;

			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}



