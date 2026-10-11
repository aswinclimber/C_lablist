/* 
Name: Aswin K U 
Roll No: CS06
Date: 10/09/2026

Experiment No : 11
 
Heading: Quick  sort
 
AIM: Implementation  of  quick  sort


ALGORITHM

1. Start.

2. Read the number of elements n.

3. Read n elements into array a.

4. Call quickSort(a, 0, n-1).

5. In quickSort:

   a. If low < high, select the first element as pivot.

   b. Initialize i = low + 1 and j = high.

   c. Move i forward while a[i] <= pivot.

   d. Move j backward while a[j] > pivot.

   e. If i < j, swap a[i] and a[j].

   f. Repeat steps c to e until i >= j.

   g. Swap the pivot with a[j].

   h. Recursively sort the left subarray.

   i. Recursively sort the right subarray.

6. Display the sorted array.

7. Stop.


SOURCE CODE
*/
#include <stdio.h>

void quickSort(int a[], int low, int high)
{
    int i, j, pivot, temp;

    if (low < high)
    {
        pivot = a[low];
        i = low + 1;
        j = high;

        while (i <= j)
        {
            while (i <= high && a[i] <= pivot)
                i++;

            while (a[j] > pivot)
                j--;

            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
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

    quickSort(a, 0, n - 1);

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
