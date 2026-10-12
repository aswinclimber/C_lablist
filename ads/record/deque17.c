/* 
Name: Aswin K U 
Roll No: CS06
Date: 05/10/2026

Experiment No : 17
 
Heading: Deque 
 
AIM: Implementation  of  Deque (double ended  queue)


ALGORITHM

1. Start.

2. Initialize front and rear pointers to NULL.

3. Display the menu with options to insert at front, insert at rear, delete from front, delete from rear, display, and exit.

4. Read the user's choice.

5. If the choice is 1, create a new node and insert it at the front of the deque.

6. If the choice is 2, create a new node and insert it at the rear of the deque.

7. If the choice is 3, check whether the deque is empty. If not, delete the front node and update the front pointer.

8. If the choice is 4, check whether the deque is empty. If not, delete the rear node and update the rear pointer.

9. If the choice is 5, display all elements from front to rear.

10. If the choice is 6, display the exit message and terminate the program.

11. If the choice is invalid, display an error message.

12. Repeat steps 3 to 11 until the choice is 6.

13. Stop.


SOURCE CODE
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *front = NULL, *rear = NULL;

void insertFront(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL)
        front = rear = newNode;
    else {
        front->prev = newNode;
        front = newNode;
    }

    printf("Inserted %d at the front.\n", data);
}

void insertRear(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted %d at the rear.\n", data);
}

void deleteFront()
{
    struct Node *temp;

    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    temp = front;
    printf("Deleted front element: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
}

void deleteRear()
{
    struct Node *temp;

    if (rear == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    temp = rear;
    printf("Deleted rear element: %d\n", temp->data);

    rear = rear->prev;

    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    free(temp);
}

void display()
{
    struct Node *temp = front;

    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, data;

    do {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertFront(data);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertRear(data);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}


/*
OUTPUT

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 1
Enter value: 10
Inserted 10 at the front.

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 2
Enter value: 20
Inserted 20 at the rear.

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 1
Enter value: 5
Inserted 5 at the front.

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 5
Deque elements: 5 10 20

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 3
Deleted front element: 5

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 4
Deleted rear element: 20

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 5
Deque elements: 10

--- Deque Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display
6. Exit
Enter your choice: 6
Exiting...

*/