#include <stdio.h>

#define MAX 10

int main()
{
    int image[MAX][MAX], transform[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of image matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter image matrix:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Enter rows and columns of transformation matrix: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter transformation matrix:\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &transform[i][j]);
        }
    }

    if(c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    /* Matrix multiplication */
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                result[i][j] += image[i][k] * transform[k][j];
            }
        }
    }

    printf("\nTransformed image matrix:\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// ALGORITHM: MATRIX MULTIPLICATION FOR IMAGE PROCESSING

// 1. Start.

// 2. Declare the image matrix, transformation matrix and result matrix.

// 3. Read the number of rows and columns of the image matrix.

// 4. Read the elements of the image matrix.

// 5. Read the number of rows and columns of the transformation matrix.

// 6. Read the elements of the transformation matrix.

// 7. Check whether the number of columns of the image matrix is equal
//    to the number of rows of the transformation matrix.

// 8. If they are not equal, display "Matrix multiplication is not possible"
//    and terminate the program.

// 9. Initialize the elements of the result matrix to zero.

// 10. Perform matrix multiplication:
//        a. Select each row of the image matrix.
//        b. Select each column of the transformation matrix.
//        c. Multiply the corresponding elements.
//        d. Add the products and store the sum in the result matrix.

// 11. Display the result matrix as the transformed image.

// 12. Stop.