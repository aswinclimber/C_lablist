
/* 
Name: Aswin K U 
Roll No: CS06
Date: 06/10/2026

Experiment No : 18
 
Heading: Priority queue
 
AIM: Implementation  of  priority queue


ALGORITHM: Priority Queue Using Heap

1. Start.

2. Initialize the heap as an empty array and set "size = 0".

3. Display the menu: Enqueue, Dequeue, Display, and Exit.

4. Read the user's choice.

5. If the choice is Enqueue:
   
   1. Check whether the heap is full. If full, display overflow.
   2. Insert the new element and its priority at the end of the heap.
   3. Compare the element with its parent.
   4. If it has higher priority, swap it with its parent.
   5. Repeat until the heap property is satisfied.

6. If the choice is Dequeue:
   
   1. Check whether the heap is empty. If empty, display underflow.
   2. Delete the root element and display its value.
   3. Move the last element to the root and decrease "size".
   4. Compare the root with its children.
   5. Swap it with the child having higher priority.
   6. Repeat until the max-heap property is restored.

7. If the choice is Display:
   
   1. If the heap is empty, display an appropriate message.
   2. Otherwise, display all elements and their priorities.

8. If the choice is Exit, terminate the program.

9. Otherwise, display an invalid-choice message.

10. Repeat steps 3–9 until the user exits.

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
int size = 0;

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

int higherPriority(struct Item a, struct Item b) {
    if (a.priority == b.priority)
        return a.data > b.data;

    return a.priority > b.priority;
}

void enqueue(int data, int priority) {
    if (size == MAX) {
        printf("Priority Queue Overflow!\n");
        return;
    }

    int i = size;

    pq[i].data = data;
    pq[i].priority = priority;
    size++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (higherPriority(pq[i], pq[parent])) {
            swap(&pq[i], &pq[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void dequeue() {
    if (size == 0) {
        printf("Priority Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", pq[0].data);

    pq[0] = pq[size - 1];
    size--;

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size &&
            higherPriority(pq[left], pq[largest])) {
            largest = left;
        }

        if (right < size &&
            higherPriority(pq[right], pq[largest])) {
            largest = right;
        }

        if (largest != i) {
            swap(&pq[i], &pq[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void display() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Value\tPriority\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    int choice, val, pri;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n");
        printf("3. Display\n4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                if (scanf("%d %d", &val, &pri) != 2)
                    return 0;
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