#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
}

struct node* createNode(int value){
	struct node* newnode;
	
	newnode = (struct node*)malloc(sizeof(struct node));

	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

struct node* insert(struct node*root, int value){
	if (root == NULL){
		return createNode(value);
	}
	else{
		if
