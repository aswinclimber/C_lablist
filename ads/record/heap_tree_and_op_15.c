/* 
Name: Aswin K U 
Roll No: CS06
Date: 25/09/2026

Experiment No : 15

Heading: Heap  tree 
 
AIM: Implementation  of  heap  tree  and  operations


ALGORITHM

1. Start.

2. Initialize the heap size n = 0.

3. Display the menu with options to insert, delete root, display, and exit.

4. Read the user's choice.

5. If the choice is 1:

   a. Check whether the heap is full.

   b. If not full, read the value and insert it into the heap.

   c. Compare the value with its parent and swap while the value is greater than its parent.

6. If the choice is 2:

   a. If the heap is empty, display "Heap is empty".

   b. Otherwise, delete the root element and replace it with the last element.

   c. Reduce the heap size by one.

   d. Compare the root with its children and swap with the largest child until the max heap property is restored.

7. If the choice is 3:

   a. If the heap is empty, display "Heap is empty".

   b. Otherwise, display all heap elements.

8. If the choice is 4, display "Exiting..." and terminate the program.

9. If the choice is invalid, display "Invalid choice".

10. Repeat steps 3 to 9 until the choice is 4.

11. Stop.


SOURCE CODE
*/
#include <stdio.h>

int heap[100], n = 0;

void insert(int value)
{
    int i, temp;

    heap[n] = value;
    i = n;
    n++;

    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void deleteRoot()
{
    int i = 0, left, right, largest, temp;

    if (n == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[n - 1];
    n--;

    while (1)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }
}

void display()
{
    int i;

    if (n == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Insert\n2. Delete Root\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (n == 100)
                    printf("Heap is full\n");
                else
                {
                    printf("Enter the value: ");
                    scanf("%d", &value);
                    insert(value);
                }
                break;

            case 2:
                deleteRoot();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}


/*
OUTPUT

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 1
Enter the value: 50

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 1
Enter the value: 30

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 1
Enter the value: 70

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 1
Enter the value: 20

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 3
Heap elements: 70 30 50 20

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 2
Deleted element: 70

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 3
Heap elements: 50 30 20

1. Insert
2. Delete Root
3. Display
4. Exit
Enter your choice: 4
Exiting...

*/