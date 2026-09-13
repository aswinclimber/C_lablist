#include <stdio.h>

int main()
{
    int n, i, j, choice;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("\nChoose pattern:\n");
    printf("1. Increasing star pattern\n");
    printf("2. Decreasing star pattern\n");
    printf("3. Number pattern\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\n");

    if(choice == 1)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    else if(choice == 2)
    {
        for(i = n; i >= 1; i--)
        {
            for(j = 1; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    else if(choice == 3)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= i; j++)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Invalid choice.");
    }

    return 0;
}

// ### ALGORITHM: PATTERN GENERATOR

// 1. Start.

// 2. Read the number of rows `n`.

// 3. Display the pattern choices:

//    * Increasing star pattern
//    * Decreasing star pattern
//    * Number pattern

// 4. Read the user's choice.

// 5. If the choice is 1:

//    * For each row from `1` to `n`, print stars equal to the row number.

// 6. If the choice is 2:

//    * For each row from `n` down to `1`, print stars equal to the row number.

// 7. If the choice is 3:

//    * For each row from `1` to `n`, print numbers from `1` to the row number.

// 8. If the choice is invalid, display an error message.

// 9. Stop.
