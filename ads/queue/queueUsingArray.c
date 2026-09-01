#include <stdio.h>

int front=queue=-1;

void enqueue(int *queue,int size){
	if(rear == size-1){
		printf("Overflow");
	}
	else{

}

void dequeue(){
}

void peek(){
}

void display(){
}

int main(){
	int size;
	printf("Enter the size of queue : ");
	scanf("%d",&size);
	int queue[size],option,n=1;
	while(n){
		printf("------QueueUsingArray------\n1. Enqueue\n2. dequeue\n3. display\n4. peek\n5. exit\n  : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				enqueue(queue,size);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			case 5:
				n = 0;
				break;
			defualt:
				printf("\nInvalid option");
			}
	}
}
	

