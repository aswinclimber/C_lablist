/* 
Name: Aswin K U 
Roll No: CS06
Date: 30/07/2026

Experiment No : 3
 
Heading: Circular  queue  using  arrays.
 
AIM: Implementation  of  circular  queue  using  arrays.


ALGORITHM

1. Start.

2. Initialize front = -1 and rear = -1.

3. Display the menu with enqueue, dequeue, display and exit options.

4. Read the user's choice.

5. If enqueue is selected, check whether the queue is full.
   If not, insert the element into the circular queue.

6. If dequeue is selected, check whether the queue is empty.
   If not, remove the front element.

7. If display is selected, print all the queue elements from front to rear.

8. Repeat steps 3 to 7 until the user selects exit.

9. Stop.

SOURCE CODE
*/
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
			printf("%d ",queue[i]);

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
		printf("\n2. Dequeue");
		printf("\n3. Display");
		printf("\n4. Exit");

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

/*
OUTPUT

1. Enqueue
2. Dequeue
3. Display
4. Exit

Enter your choice: 1
Enter value: 10

Enter your choice: 1
Enter value: 20

Enter your choice: 1
Enter value: 30

Enter your choice: 3
Queue elements: 10 20 30

Enter your choice: 2

Enter your choice: 3
Queue elements: 20 30

Enter your choice: 4
*/

