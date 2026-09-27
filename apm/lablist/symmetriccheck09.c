/* 
Name: Aswin K U 
Roll No: CS06
Date: 26/08/2026
 
******** Symmetry Checker for Geometric Designs ******** 
 
AIM: Develop a program to check if a given design (represented as a matrix) is symmetric. This program can be useful for analyzing symmetry in architectural or geometric design patterns.

ALGORITHM

1. Start.

2. Declare a square matrix and required variables.

3. Read the order of the matrix.

4. Read the elements of the matrix.

5. Initialize the variable `symmetric` to 1.

6. Compare each element `a[i][j]` with its corresponding transposed element `a[j][i]`.

7. If `a[i][j]` is not equal to `a[j][i]`:
   a. Set `symmetric` to 0.
   b. Stop the comparison.

8. If `symmetric` is equal to 1, display "The design is symmetric."

9. Otherwise, display "The design is not symmetric."

10. Stop.

SOURCE CODE
*/
#include <stdio.h>

#define MAX 10

int main()
{
    int a[MAX][MAX];
    int n, i, j, symmetric = 1;

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    printf("Enter the matrix elements:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    /* Check for symmetry */
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                symmetric = 0;
                break;
            }
        }

        if(symmetric == 0)
        {
            break;
        }
    }

    if(symmetric == 1)
    {
        printf("The design is symmetric.\n");
    }
    else
    {
        printf("The design is not symmetric.\n");
    }

    return 0;
}

/*
OUTPUT

Enter the order of the matrix: 3
Enter the matrix elements:
1 2 3
2 4 5
3 5 6

The design is symmetric.
*/
