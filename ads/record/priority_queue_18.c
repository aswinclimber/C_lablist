/* 
Name: Aswin K U 
Roll No: CS06
Date: 06/10/2026

Experiment No : 18
 
Heading: Priority queue
 
AIM: Implementation  of  priority queue


ALGORITHM

1. Start.

2. Initialize size = -1 and define the maximum size of the priority queue as 100.

3. Display the menu with options to enqueue, dequeue, display, and exit.

4. Read the user's choice.

5. If the choice is 1:

   a. Read the value and its priority.

   b. Check whether the priority queue is full.

   c. If full, display an overflow message.

   d. Otherwise, insert the value and priority into the queue and increment size.

6. If the choice is 2:

   a. Check whether the priority queue is empty.

   b. If empty, display an underflow message.

   c. Otherwise, find the element with the highest priority.

   d. If priorities are equal, select the element with the larger value.

   e. Display and delete the selected element.

   f. Shift the remaining elements to fill the empty position and decrement size.

7. If the choice is 3:

   a. If the queue is empty, display an empty message.

   b. Otherwise, display all elements along with their priorities.

8. If the choice is 4, terminate the program.

9. If the choice is invalid, display an error message.

10. Repeat steps 3 to 9 until the user chooses to exit.

11. Stop.


SOURCE CODE
*/
#include <stdio.h>
#define MAX 100

struct Item {
    int data;
    int priority;
};

struct Item pq[MAX];
int size = -1;

void enqueue(int data, int priority) {
    if (size >= MAX - 1) {
        printf("Priority Queue Overflow!\n");
        return;
    }

    size++;
    pq[size].data = data;
    pq[size].priority = priority;
}

int peek() {
    int highestPriority = -1089203;
    int ind = -1;

    for (int i = 0; i <= size; i++) {
        if (highestPriority == pq[i].priority && ind > -1 && pq[ind].data < pq[i].data) {
            highestPriority = pq[i].priority;
            ind = i;
        } else if (pq[i].priority > highestPriority) {
            highestPriority = pq[i].priority;
            ind = i;
        }
    }

    return ind;
}

void dequeue() {
    if (size < 0) {
        printf("Priority Queue Underflow!\n");
        return;
    }

    int ind = peek();

    printf("Deleted element: %d\n", pq[ind].data);

    for (int i = ind; i < size; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

void display() {
    if (size < 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    for (int i = 0; i <= size; i++) {
        printf("Value: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    int choice, val, pri;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &val, &pri);
                enqueue(val, pri);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


/*
OUTPUT

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 10 2

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 20 3

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value and priority: 30 1

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3
Value: 10, Priority: 2
Value: 20, Priority: 3
Value: 30, Priority: 1

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 2
Deleted element: 20

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3
Value: 10, Priority: 2
Value: 30, Priority: 1

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 4
*/