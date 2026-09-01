#include <stdio.h>
int top= -1;
void push(int stack[],int size){
	int value;
	printf("Ente the value you want to push : ");
	scanf("%d",&value);
	if(top == size-1){
		printf("stack overflow");
	}
	else{
		top++;
		stack[top]=value;
	}
}

void pop(int stack[]){
	if (top == -1){
		printf("stack underflow");
	}
	else{
		printf("your poped value %d",stack[top]);
		top--;
	}
}

void peek(int stack[]){
	if(top == -1){
		printf("\nno values entered");
	}
	else{
		printf("top value : %d",stack[top]);
	}
}

int main(){
	int size,i,value,option;
	printf("Enter the size of stack : ");
	scanf("%d",&size);
	int stack[size];
	
	int n = 1;
	while(n){
	printf("\nenter the operations you want to perform : \n1. push \n2. pop\n3. peek \n4. exit \n   :  ");
	scanf("%d",&option);
		switch(option){
		case 1:
			push(stack,size);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
			peek(stack);
			break;
		case 4:
			n = 0;
			break;
		default :
			printf("invalid option");
		}
	}
	return 0;
}

			

