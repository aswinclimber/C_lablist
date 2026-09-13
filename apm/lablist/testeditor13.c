#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], sub[50], result[150];
    int pos, i, j, k;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    printf("Enter the substring to insert: ");
    scanf("%s", sub);

    printf("Enter the position: ");
    scanf("%d", &pos);

    if(pos < 0 || pos > strlen(text))
    {
        printf("Invalid position.\n");
        return 0;
    }

    i = 0;

    while(i < pos)
    {
        result[i] = text[i];
        i++;
    }

    j = 0;

    while(sub[j] != '\0')
    {
        result[i] = sub[j];
        i++;
        j++;
    }

    k = pos;

    while(text[k] != '\0')
    {
        result[i] = text[k];
        i++;
        k++;
    }

    result[i] = '\0';

    printf("Updated text: %s\n", result);

    return 0;
}

// ### ALGORITHM: SUBSTRING INSERTION

// 1. Start.

// 2. Read the existing text.

// 3. Read the substring to be inserted.

// 4. Read the position at which the substring is to be inserted.

// 5. Check whether the position is valid.

//    * If the position is invalid, display an error message and stop.

// 6. Copy the characters of the original text before the specified position into the result string.

// 7. Copy the substring into the result string.

// 8. Copy the remaining characters of the original text into the result string.

// 9. Add the null character `'\0'` at the end of the result string.

// 10. Display the updated text.

// 11. Stop.
