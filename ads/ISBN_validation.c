#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
	char ch;
	struct Node*next;
};

struct Node* createNode(char ch){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	newNode->ch = ch;
	newNode->next = Null;
	return newNode;

}

void appendNode(struct Node**head,struct Node** tail, char ch){
	Node* newNode = createNode(ch);
	if (*head == NULL){
		*head = newNode;
		*tail = newNode;
	}
	else{
		(*tail)->next = newNode;
		*tail = newNode;
	}
}
void freeList(struct Node* head){
	while(head != NULL){
		struct Node* temp = head;
		head = head->next;
		free(temp);
	}
}

void processISBN(const char* input){
	int len = strlen(input);

	for(int i = 0;i<len;i++){
		if(!isdigit(input[i])){
			printf("Error: input must contain digits only. \n");
			return;
		}
	}
	if (len !=9

