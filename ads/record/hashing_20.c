/* 
Name: Aswin K U 
Roll No: CS06
Date: 09/10/2026

Experiment No : 20
 
Heading: Hashing 
 
AIM: Implementation  of  hashing  using  separate  chaining   


ALGORITHM

1.  Start.

2.  Define a hash table of size SIZE and initialize all entries to NULL.

3.  Define the hash function as h(key) = key % SIZE.

4   Implement INSERT operation:
    a. Read the value to insert.
    b. Calculate index = h(key).
    c. Create a new node containing the key.
    d. If the index is empty, insert the node there.
    e. Otherwise, traverse the linked list and insert the node at the end.

5.  Implement DISPLAY operation:
    a. Traverse each index of the hash table.
    b. Display all elements in the linked list at each index.

6.  Display the menu and read the user's choice.

7.  Repeat the insertion and display operations until the user selects Exit.

8.  Stop.

SOURCE CODE
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE];

void initHash() {
    int i;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = NULL;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    struct Node *newnode, *temp;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = key;
    newnode->next = NULL;

    if (hashTable[index] == NULL)
        hashTable[index] = newnode;
    else {
        temp = hashTable[index];

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("Inserted %d at index %d\n", key, index);
}

void display() {
    int i;
    struct Node *temp;

    for (i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        temp = hashTable[i];

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    int ch, val;

    initHash();

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                display();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/*
OUTPUT

1. Insert
2. Display
3. Exit
Enter choice: 1
Enter value: 10
Inserted 10 at index 0

1. Insert
2. Display
3. Exit
Enter choice: 1
Enter value: 20
Inserted 20 at index 0

1. Insert
2. Display
3. Exit
Enter choice: 1
Enter value: 15
Inserted 15 at index 5

1. Insert
2. Display
3. Exit
Enter choice: 2
Index 0: 10 -> 20 -> NULL
Index 1: NULL
Index 2: NULL
Index 3: NULL
Index 4: NULL
Index 5: 15 -> NULL
Index 6: NULL
Index 7: NULL
Index 8: NULL
Index 9: NULL

1. Insert
2. Display
3. Exit
Enter choice: 3
*/