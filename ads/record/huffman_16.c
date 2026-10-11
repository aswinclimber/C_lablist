/* 
Name: Aswin K U 
Roll No: CS06
Date: 30/09/2026

Experiment No : 16
 
Heading: Huffman  algorithm
 
AIM: Implementation  of  Huffman  algorithm


ALGORITHM

1. Start.

2. Read the number of characters n.

3. Read each character and its frequency.

4. Create a leaf node for each character with its frequency and set its left and right children to -1.

5. Repeat the following steps n - 1 times:

   a. Find the two unused nodes with the smallest frequencies.

   b. Mark both nodes as used.

   c. Create a new internal node with the sum of their frequencies.

   d. Set the two selected nodes as the left and right children of the new node.

6. The last created node becomes the root of the Huffman tree.

7. Call printCodes(root, code, 0).

8. In printCodes:

   a. If the current node is a leaf node, terminate the code string and display the character and its Huffman code.

   b. If the left child exists, append '0' to the code and recursively traverse the left subtree.

   c. If the right child exists, append '1' to the code and recursively traverse the right subtree.

9. Display the Huffman codes for all characters.

10. Stop.


SOURCE CODE
*/
#include <stdio.h>

struct Node
{
    char ch;
    int freq;
    int left, right;
};

struct Node tree[100];
int count = 0;

int createNode(char ch, int freq, int left, int right)
{
    tree[count].ch = ch;
    tree[count].freq = freq;
    tree[count].left = left;
    tree[count].right = right;
    return count++;
}

void printCodes(int root, char code[], int top)
{
    if (tree[root].left == -1 && tree[root].right == -1)
    {
        code[top] = '\0';
        printf("%c : %s\n", tree[root].ch, code);
        return;
    }

    if (tree[root].left != -1)
    {
        code[top] = '0';
        printCodes(tree[root].left, code, top + 1);
    }

    if (tree[root].right != -1)
    {
        code[top] = '1';
        printCodes(tree[root].right, code, top + 1);
    }
}

int main()
{
    int n, i, j, min1, min2, root;
    int freq[50], used[50] = {0};
    char ch[50], code[50];

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    printf("Enter characters and frequencies:\n");
    for (i = 0; i < n; i++)
        scanf(" %c %d", &ch[i], &freq[i]);

    for (i = 0; i < n; i++)
        createNode(ch[i], freq[i], -1, -1);

    for (i = 0; i < n - 1; i++)
    {
        min1 = -1;
        min2 = -1;

        for (j = 0; j < count; j++)
        {
            if (used[j] == 0)
            {
                if (min1 == -1 || tree[j].freq < tree[min1].freq)
                {
                    min2 = min1;
                    min1 = j;
                }
                else if (min2 == -1 || tree[j].freq < tree[min2].freq)
                {
                    min2 = j;
                }
            }
        }

        used[min1] = 1;
        used[min2] = 1;

        root = createNode('#', tree[min1].freq + tree[min2].freq,
                          min1, min2);
    }

    printf("Huffman Codes:\n");
    printCodes(root, code, 0);

    return 0;
}


/*
OUTPUT

Enter the number of characters: 4

Enter characters and frequencies:
A 5
B 9
C 12
D 13

Huffman Codes:
C : 00
D : 01
A : 100
B : 101

*/