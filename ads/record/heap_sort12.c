/* 
Name: Aswin K U 
Roll No: CS06
Date: 16/09/2026

Experiment No : 12
 
Heading: Heap  sort

AIM: Implementation  of  heap  sort


ALGORITHM

1. Start.

2. Read the number of elements n.

3. Read n elements into array a.

4. Call heapSort(a, n).

5. In heapSort:

   a. Build a max heap by calling heapify for all non-leaf nodes, starting from n/2 - 1 down to 0.

   b. Swap the root element with the last element.

   c. Reduce the heap size by one.

   d. Call heapify to maintain the max heap property.

   e. Repeat steps b to d until the heap size becomes 1.

6. Display the sorted array.

7. Stop.


SOURCE CODE
*/
#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int largest, left, right, temp;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heapSort(a, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}


/*
OUTPUT

Enter the number of elements: 5

Enter the elements:
64 25 12 22 11

Sorted array:
11 12 22 25 64

*/
