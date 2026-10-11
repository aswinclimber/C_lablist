/* 
Name: Aswin K U 
Roll No: CS06
Date: 11/08/2026

Experiment No : 5
 
Heading: Stacks  using  linkedlist
 
AIM: Implementation  of  stacks  using  linkedlist


ALGORITHM

1. Start.

2. Initialize top = NULL.

3. Display the menu with Push, Pop, Peep and Exit operations.

4. Read the user's choice.

5. If Push is selected, create a new node, read the data and insert it at the top of the stack.

6. If Pop is selected, check whether the stack is empty.
   If empty, display Underflow.
   Otherwise, remove the top node and display its value.

7. If Peep is selected, check whether the stack is empty.
   If empty, display Stack is empty.
   Otherwise, display the top element.

8. Repeat steps 3 to 7 until the user selects Exit.

9. Stop.


SOURCE CODE
*/
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


/*
OUTPUT

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 1
Enter the data : 10

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 1
Enter the data : 20

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 1
Enter the data : 30

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 3
top value : 30

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 2
Poped value : 30

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 3
top value : 20

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 2
Poped value : 20

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 2
Poped value : 10

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 2
Underflow
choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 3
Stack is empty

choose the operation you want to perform :
1. Push
2. pop
3. peep
4. exit
: 4
*/