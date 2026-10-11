/* 
Name: Aswin K U 
Roll No: CS06
Date: 21/07/2026

Experiment No : 1
 
Heading: Stacks Using Arrays
 
AIM: Implementation  of  stacks  using  arrays


ALGORITHM

1. Start.

2. Initialize `top` to `-1`.

3. Read the size of the stack and create an array `stack` of that size. 

4. Display the menu with options: Push, Pop, Peek, and Exit.

5. Read the user's choice.

6. If the choice is Push:
   1. Read the value to be pushed.
   2. Check whether `top == size - 1`.
   3. If true, display Stack Overflow.
   4. Otherwise, increment `top` and insert the value into `stack[top]`.

7. If the choice is Pop:
   1. Check whether `top == -1`.
   2. If true, display Stack Underflow.
   3. Otherwise, display `stack[top]` and decrement `top`.

8. If the choice is Peek:
   1. Check whether `top == -1`.
   2. If true, display that there are no values.
   3. Otherwise, display `stack[top]` as the top value.
   
9. If the choice is **Exit**, terminate the menu loop.

10. If an invalid choice is entered, display **Invalid Option**.

11. Repeat steps 4 to 10 until the user chooses Exit.

12. Stop.


SOURCE CODE
*/
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

/* 
OUTPUT

Enter the size of stack : 3

enter the operations you want to perform :
1. push
2. pop
3. peek
4. exit
   : 1
Ente the value you want to push : 10

enter the operations you want to perform :
1. push
2. pop
3. peek
4. exit
   : 1
Ente the value you want to push : 20

enter the operations you want to perform :
1. push
2. pop
3. peek
4. exit
   : 3
top value : 20

enter the operations you want to perform :
1. push
2. pop
3. peek
4. exit
   : 2
your poped value 20

enter the operations you want to perform :
1. push
2. pop
3. peek
4. exit
   : 3
top value : 10

enter the operations you want to perform :
1. push
2. pop
3. peek
4. exit
   : 4			
*/
