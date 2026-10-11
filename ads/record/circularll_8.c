/* 
Name: Aswin K U 
Roll No: CS06
Date: 26/08/2026

Experiment No : 8 
 
Heading: Circular  linkedlist.
 
AIM: Implementation  of  circular  linkedlist.


ALGORITHM

1. Start.

2. Initialize head = NULL.

3. Display the menu with insertion, deletion, display and exit options.

4. Read the user's choice.

5. If insertion at beginning is selected, create a new node and link it before the head while maintaining circular links.

6. If insertion at end is selected, create a new node and link it after the last node, connecting it back to the head.

7. If insertion in between is selected, read the value to insert and the preceding record, locate the node and insert the new node after it.

8. If deletion is selected, search for the given value, update the previous and next links, and free the node.

9. If display is selected, traverse the circular linked list from head until head is reached again and display all elements.

10. Repeat steps 3 to 9 until the user selects Exit.

11. Stop.


SOURCE CODE
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} node;

node* head = NULL;

node* createNode(int value) {
    node* newnode = (node*)malloc(sizeof(node));

    newnode->data = value;
    newnode->next = newnode;
    newnode->prev = newnode;

    return newnode;
}

void insertionAtBeginning(int value) {
    node* newnode = createNode(value);

    if (head == NULL) {
        head = newnode;
    }
    else {
        node* last = head->prev;

        newnode->next = head;
        newnode->prev = last;
        head->prev = newnode;
        last->next = newnode;
        head = newnode;
    }

    printf("Inserted %d at the beginning.", value);
}

void insertionAtEnd(int value) {
    node* newnode = createNode(value);

    if (head == NULL) {
        head = newnode;
    }
    else {
        node* last = head->prev;

        last->next = newnode;
        newnode->prev = last;
        newnode->next = head;
        head->prev = newnode;
    }

    printf("Inserted %d at the end.", value);
}

void insertionAfterValue(int value, int position) {
    if (head == NULL) {
        printf("List is empty.");
        return;
    }

    node* temp = head;

    do {
        if (temp->data == position) {
            node* newnode = createNode(value);

            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next->prev = newnode;
            temp->next = newnode;

            printf("Inserted %d after %d.", value, position);
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Value %d not found in list.", position);
}

void deletion(int value) {
    if (head == NULL) {
        printf("List is empty.");
        return;
    }

    node* temp = head;

    do {
        if (temp->data == value) {
            if (temp->next == temp) {
                head = NULL;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head) {
                    head = temp->next;
                }
            }

            free(temp);

            printf("Deleted %d from the list.", value);
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Element %d not found in the list.", value);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.");
        return;
    }

    node* temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Circular Linked List Operations Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert In Between (at Position)\n");
        printf("4. Delete a Node\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            return 0;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                if (scanf("%d", &value) == 1) {
                    insertionAtBeginning(value);
                }
                break;

            case 2:
                printf("Enter value to insert at end: ");
                if (scanf("%d", &value) == 1) {
                    insertionAtEnd(value);
                }
                break;

            case 3:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) == 1) {
                    displayList();

                    printf("\nEnter preceding record: ");
                    if (scanf("%d", &position) == 1) {
                        insertionAfterValue(value, position);
                    }
                }
                break;

            case 4:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) == 1) {
                    deletion(value);
                }
                break;

            case 5:
                displayList();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please try again.");
        }
    }

    return 0;
}


/*
--- Circular Linked List Operations Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert In Between (at Position)
4. Delete a Node
5. Display
6. Exit
Enter your choice: 1
Enter value to insert at beginning: 10
Inserted 10 at the beginning.
--- Circular Linked List Operations Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert In Between (at Position)
4. Delete a Node
5. Display
6. Exit
Enter your choice: 2
Enter value to insert at end: 20
Inserted 20 at the end.
--- Circular Linked List Operations Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert In Between (at Position)
4. Delete a Node
5. Display
6. Exit
Enter your choice: 2
Enter value to insert at end: 30
Inserted 30 at the end.
--- Circular Linked List Operations Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert In Between (at Position)
4. Delete a Node
5. Display
6. Exit
Enter your choice: 3
Enter value to insert: 15
Circular Linked List: 10 -> 20 -> 30 -> (head)
Enter preceding record: 10
Inserted 15 after 10.
--- Circular Linked List Operations Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert In Between (at Position)
4. Delete a Node
5. Display
6. Exit
Enter your choice: 5
Circular Linked List: 10 -> 15 -> 20 -> 30 -> (head)
--- Circular Linked List Operations Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert In Between (at Position)
4. Delete a Node
5. Display
6. Exit
Enter your choice: 4
Enter value to delete: 20
Deleted 20 from the list.
--- Circular Linked List Operations Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert In Between (at Position)
4. Delete a Node
5. Display
6. Exit
Enter your choice: 5
Circular Linked List: 10 -> 15 -> 30 -> (head)
--- Circular Linked List Operations Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert In Between (at Position)
4. Delete a Node
5. Display
6. Exit
Enter your choice: 6
*/