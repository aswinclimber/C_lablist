#include <stdio.h>
#include <string.h>

void reverseWords(char str[], int start, int end)
{
    int i;

    if(start > end)
        return;

    for(i = start; i <= end; i++)
    {
        if(str[i] == ' ')
        {
            reverseWords(str, i + 1, end);

            printf("%.*s ", i - start, str + start);
            return;
        }
    }

    /* Print the last word */
    printf("%s ", str + start);
}

int main()
{
    char str[200];
    int len;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    len = strlen(str);

    printf("Reversed sentence: ");
    reverseWords(str, 0, len - 1);

    printf("\n");

    return 0;
}


// ### ALGORITHM: RECURSION-BASED SENTENCE REVERSAL

// 1. Start.

// 2. Read the sentence.

// 3. Remove the newline character from the input sentence.

// 4. Find the length of the sentence.

// 5. Call the recursive function `reverseWords()` with the starting position `0` and the last position of the sentence.

// 6. In the recursive function:

//    * Start from the given position and search for a space or the end of the string.
//    * If a space or the end of the string is found, recursively call the function for the next word.
//    * After the recursive call returns, print the current word.

// 7. Continue until all words are printed in reverse order.

// 8. Display the reversed sentence.

// 9. Stop.
