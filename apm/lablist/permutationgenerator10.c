#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char str[], int left, int right)
{
    int i;

    if(left == right)
    {
        printf("%s\n", str);
    }
    else
    {
        for(i = left; i <= right; i++)
        {
            swap(&str[left], &str[i]);

            permute(str, left + 1, right);

            swap(&str[left], &str[i]);
        }
    }
}

int main()
{
    char str[50];
    int n;

    printf("Enter a string: ");
    scanf("%s", str);

    n = strlen(str);

    printf("\nAll possible permutations:\n");
    permute(str, 0, n - 1);

    return 0;
}


/*
ALGORITHM: PERMUTATION GENERATOR

1. Start.

2. Read the input string.

3. Find the length of the string.

4. Call the permutation function with the first and last
   positions of the string.

5. In the permutation function:
      a. If the current position reaches the last position,
         display the string.
      b. Otherwise, select each character from the current
         position to the last position.
      c. Swap the selected character with the character at
         the current position.
      d. Recursively generate permutations for the next position.
      e. Swap the characters back to restore the original order.

6. Repeat the process until all possible permutations are generated.

7. Display all the generated permutations.

8. Stop.
*/