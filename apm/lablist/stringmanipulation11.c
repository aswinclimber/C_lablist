#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

int main()
{
    char str[MAX][50];
    char result[100];
    int n, i, choice, cmp;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("\nEnter the strings:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }

    printf("\n--- String Manipulation Utility ---\n");
    printf("1. Concatenation\n");
    printf("2. Comparison\n");
    printf("3. Convert to lowercase\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        strcpy(result, str[0]);

        for(i = 1; i < n; i++)
        {
            strcat(result, str[i]);
        }

        printf("Concatenated string: %s\n", result);
    }
    else if(choice == 2)
    {
        if(n >= 2)
        {
            cmp = strcmp(str[0], str[1]);

            if(cmp == 0)
                printf("The two strings are equal.\n");
            else if(cmp < 0)
                printf("First string is smaller than the second string.\n");
            else
                printf("First string is greater than the second string.\n");
        }
        else
        {
            printf("At least two strings are required for comparison.\n");
        }
    }
    else if(choice == 3)
    {
        for(i = 0; i < n; i++)
        {
            int j;

            for(j = 0; str[i][j] != '\0'; j++)
            {
                str[i][j] = tolower(str[i][j]);
            }

            printf("String %d: %s\n", i + 1, str[i]);
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}


/*
ALGORITHM: STRING MANIPULATION UTILITY

1. Start.

2. Declare an array to store the user-provided strings.

3. Read the number of strings.

4. Read all the strings from the user.

5. Display the available string operations:
      a. Concatenation
      b. Comparison
      c. Conversion to lowercase

6. Read the user's choice.

7. If the choice is concatenation:
      a. Copy the first string to the result.
      b. Append the remaining strings to the result.
      c. Display the concatenated string.

8. If the choice is comparison:
      a. Compare the first two strings.
      b. Display whether the strings are equal,
         or which string is greater.

9. If the choice is conversion to lowercase:
      a. Traverse each string character by character.
      b. Convert each uppercase character to lowercase.
      c. Display the converted strings.

10. If an invalid choice is entered, display an appropriate message.

11. Stop.
*/