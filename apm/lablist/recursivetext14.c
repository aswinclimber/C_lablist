/* 
Name: Aswin K U 
Roll No: CS06
Date: 15/09/2026
 
******** Recursion-Based Sentence Reversal for Voice Transcription ******** 
 
AIM: Write a program that reverses the words of a sentence, using recursion. This could be applied in a speech-to-text application where the order of words needs to be reversed for analysis.

ALGORITHM

1. Start.

2. Read the sentence.

3. Remove the newline character from the input sentence.

4. Find the length of the sentence.

5. Call the recursive function `reverseWords()` with the starting position `0` and the last position of the sentence.

6. In the recursive function:
   * Start from the given position and search for a space or the end of the string.
   * If a space or the end of the string is found, recursively call the function for the next word.
   * After the recursive call returns, print the current word.

7. Continue until all words are printed in reverse order.

8. Display the reversed sentence.

9. Stop.

SOURCE CODE
*/
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

/*
OUTPUT

Enter a sentence: I love computer science
Reversed sentence: science computer love I
*/
