/* 
Name: Aswin K U 
Roll No: CS06
Date: 11/08/2026 

Experiment No : 6
 
Heading: Dynamic Data Display (Pascal's Triangle and Patterns) 
 
AIM: Develop an application that displays Pascal's Triangle dynamically based on user input for the number of rows.Also, create a pattern generator (star pyramid pattern) that can be customized with user input

ALGORITHM

1. Start.

2. Read the number of rows `n`.

3. Repeat for each row from `0` to `n-1`:
   * Print spaces to format the triangle.
   * Set `num = 1`.
   * Repeat for each element in the current row:
     * Display `num`.
     * Calculate the next value of `num` using the Pascal's Triangle formula.

4. Move to the next row.

5. Stop.

SOURCE CODE
*/
#include <stdio.h>

int main(){
	int n, i, j,num;
	printf("Enter number of rows : ");
	scanf("%d",&n);

	printf("pascal's Triangle : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			printf(" ");
		}

		num = 1;
		
		for(j=0;j<=i;j++){
			printf("%d ",num);
			num = num*(i-j)/(j+1);
		}
		printf("\n");
	}
	return 0;
}

/*
OUTPUT

Enter no. of rows: 5  

        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1


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
