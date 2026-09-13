#include <stdio.h>

int main()
{
    char str[100], rev[100];
    int i, j, length = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    /* Find the length manually */
    while (str[length] != '\0')
    {
        length++;
    }

    /* Reverse the string manually */
    j = 0;

    for (i = length - 1; i >= 0; i--)
    {
        rev[j] = str[i];
        j++;
    }

    rev[j] = '\0';

    printf("Reversed string: %s\n", rev);

    /* Compare original and reversed string manually */
    i = 0;

    while (str[i] != '\0')
    {
        if (str[i] != rev[i])
        {
            printf("Not a palindrome\n");
            return 0;
        }
        i++;
    }

    printf("Palindrome\n");

    return 0;
}

// ### Algorithm: Check Whether a String is a Palindrome

// 1. **Start**
// 2. Declare a string `str` and another string `rev`.
// 3. Read the string `str`.
// 4. Find the length of `str` manually.
// 5. Set `j = 0`.
// 6. Start from the last character of `str`.
// 7. Copy each character into `rev` from last to first.
// 8. Add `'\0'` at the end of `rev`.
// 9. Compare `str` and `rev` character by character.
// 10. If all characters are the same, print **"Palindrome"**.
// 11. Otherwise, print **"Not a Palindrome"**.
// 12. **Stop**.
