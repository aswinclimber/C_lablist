#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node*next;
};

void printList(struct Node*head){
	struct Node*temp = head;

	printf("Linked list: ");
	while(temp != NULL){
		printf("%d ->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void append(struct Node**head_ref, int new_data){
	struct Node*new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	else{
		struct Node*last = *head_ref;
		while (last->next != NULL){
			last = last->next;
		}

		last->next = new_node;
	}
}
int main(){
	struct Node* head = NULL;

	append(&head,10);
	append(&head,20);
	append(&head,30);
	append(&head,40);

	printList(head);

	return 0;
}




