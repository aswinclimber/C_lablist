/* 
Name: Aswin K U 
Roll No: CS06
Date: 04/09/2026

Experiment No : 10
 
Heading: Binary  search  trees 
 
AIM: Implementation  of  binary  search  trees  and  perform  the    operations  on  BST


ALGORITHM

1. Start.

2. Define a structure node containing data, left pointer and right pointer.

3. Initialize root = NULL.

4. Create a function createNode(value) to allocate memory for a new node and initialize its data, left and right pointers.

5. Display the menu with insertion, search, inorder, preorder, postorder and exit options.

6. Read the user's choice.

7. If insertion is selected, read the value and insert it into the Binary Search Tree:
   a. If the tree is empty, create the root node.
   b. If the value is smaller than the current node, insert it into the left subtree.
   c. If the value is greater than the current node, insert it into the right subtree.

8. If search is selected, read the key and compare it with the current node:
   a. If the key matches, display "Key is found".
   b. If the key is smaller, search the left subtree.
   c. If the key is greater, search the right subtree.
   d. If the key is not present, display "Key is not found".

9. If inorder traversal is selected, traverse the left subtree, display the node data and traverse the right subtree.

10. If preorder traversal is selected, display the node data, traverse the left subtree and traverse the right subtree.

11. If postorder traversal is selected, traverse the left subtree, traverse the right subtree and display the node data.

12. Repeat steps 5 to 11 until the user selects Exit.

13. Stop.


SOURCE CODE
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    int data;
    struct Node* right;
} node;

node* root = NULL;

node* createNode(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* insert(node* tree, int value) {
    if (tree == NULL) {
        return createNode(value);
    }

    if (value < tree->data) {
        tree->left = insert(tree->left, value);
    }
    else if (value > tree->data) {
        tree->right = insert(tree->right, value);
    }

    return tree;
}

void searchNode(node* tree, int key) {
    if (tree == NULL) {
        printf("\nKey is not found");
        return;
    }

    if (key == tree->data) {
        printf("\nKey is found");
    }
    else if (key < tree->data) {
        searchNode(tree->left, key);
    }
    else {
        searchNode(tree->right, key);
    }
}

void inorder(node* tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

void preorder(node* tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(node* tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->data);
    }
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\n\n==== Tree Menu ====\n");
        printf("1. Insertion\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("\nEnter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("\nEnter key: ");
                scanf("%d", &key);
                searchNode(root, key);
                break;

            case 3:
                printf("\nInorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("\nPreorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("\nPostorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                return 0;

            default:
                printf("\nEnter a valid input");
        }
    }

    return 0;
}


/*
OUTPUT

==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1

Enter value to insert: 50


==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1

Enter value to insert: 30


==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1

Enter value to insert: 70


==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1

Enter value to insert: 20


==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1

Enter value to insert: 40


==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 2

Enter key: 40
Key is found

==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 3

Inorder Traversal: 20 30 40 50 70 

==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 4

Preorder Traversal: 50 30 20 40 70 

==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 5

Postorder Traversal: 20 40 30 70 50 

==== Tree Menu ====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 6
*/