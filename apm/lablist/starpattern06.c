/* 
Name: Aswin K U 
Roll No: CS06
Date: 12/08/2026
 
******** Dynamic Data Display (Pascal's Triangle and Patterns) ******** 
 
AIM:  b) Also, create a pattern generator (star pyramid pattern) that can be customized with user input

ALGORITHM

1. Start.

2. Declare integer variables `n`, `i`, and `j`.

3. Read the number of rows `n`.

4. Repeat for `i = 1` to `n`.

5. Print spaces using a loop from `j = i` to `n - 1`.

6. Print `i` stars using a loop from `j = 1` to `i`.

7. Move to the next line.

8. Repeat steps 4 to 7 until all rows are printed.

9. Stop.

SOURCE CODE
*/
#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        for(j = i; j < n; j++)
        {
            printf(" ");
        }

        for(j = 1; j <= i; j++)
        {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}

/*
OUTPUT

Enter number of rows: 5  

    *
   * *
  * * *
 * * * *
* * * * *
*/
