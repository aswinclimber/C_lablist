/* 
Name: Aswin K U 
Roll No: CS06
Date: 07/10/2026

Experiment No : 19
 
Heading: AVL  tree 
 
AIM: Implementation of   AVL  tree (balanced  tree).


ALGORITHM

1.  Start.

2.  Define a node with data, height, left pointer and right pointer.

3.  Create functions to calculate the height and balance factor of a node.

4.  Create left and right rotation functions to balance the AVL tree.

5.  Insert elements into the tree according to the Binary Search Tree property.

6.  Update the height and calculate the balance factor after insertion.

7.  Perform LL, RR, LR or RL rotations whenever the tree becomes unbalanced.

8.  Search for an element by comparing it with the current node.

9.  Perform inorder, preorder and postorder traversals when requested.

10. Repeat the menu operations until the user selects Exit.

11. Stop.


SOURCE CODE
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, height;
    struct Node *left, *right;
};

struct Node *root = NULL;

int height(struct Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node *create(int data) {
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;

    return newnode;
}

int balance(struct Node *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int data) {
    if (node == NULL)
        return create(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;

    int b = balance(node);

    if (b > 1 && data < node->left->data)
        return rightRotate(node);

    if (b < -1 && data > node->right->data)
        return leftRotate(node);

    if (b > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (b < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void search(struct Node *node, int key) {
    if (node == NULL) {
        printf("Key not found\n");
        return;
    }

    if (key == node->data)
        printf("Key found\n");
    else if (key < node->data)
        search(node->left, key);
    else
        search(node->right, key);
}

void inorder(struct Node *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(struct Node *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct Node *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    int ch, data, key;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Traversal\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted successfully\n");
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(root, key);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);

                printf("\nPreorder: ");
                preorder(root);

                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/*
OUTPUT

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 1
Enter value: 30
Inserted successfully

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 1
Enter value: 20
Inserted successfully

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 1
Enter value: 10
Inserted successfully

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 3
Inorder: 10 20 30
Preorder: 20 10 30
Postorder: 10 30 20

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 2
Enter key: 20
Key found

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 2
Enter key: 50
Key not found

1. Insert
2. Search
3. Traversal
4. Exit
Enter choice: 4
*/