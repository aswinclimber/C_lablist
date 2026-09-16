#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
}

int main(){
	printf("Enter the data ");
	struct node*newnode;
	newnode =(struct node)*malloc(sizeof(struct node));
	scanf("%d",&newnode->data)
