#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *top, *newnode;

void push(){
	newnode  = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;

	if (top == NULL){
		top=newnode;
	}
	else{
		newnode->next = top;
		top = newnode;
	}
}

void pop(){
	if(top==NULL){
		printf("Underflow");
	}
	else{
		printf("Poped value : %d",top->data);
		top = top->next;
	}

}

void peep(){
	if (top==NULL){
		printf("Stack is empty");
	}
	else{
		printf("top value : %d", top->data);
	}
}

int main(){
	top = NULL;
	int option,n=1;
	while(n){
		printf("choose the operation you  want to perform : \n1. Push\n2. pop\n3. peep \n4. exit\n : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peep();
				break;
			case 4:
				n = 0;
				break;
			default:
				printf("invalid input");
				break;
		}
	}
}
