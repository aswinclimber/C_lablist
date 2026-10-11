/* 
Name: Aswin K U 
Roll No: CS06
Date: 01/09/2026

Experiment No : 9
 
Heading: Binary  tree  and  traversals.
 
AIM: Implementation  of  binary  tree  and  traversals.


ALGORITHM

1. Start.

2. Define a structure node containing data, left pointer and right pointer.

3. Create a function createNode(value) to allocate memory for a new node, assign the value and initialize left and right pointers to NULL.

4. Read the number of nodes, n.

5. If n <= 0, display "Tree is empty" and stop.

6. Repeat n times:
   a. Read the data value.
   b. If the root is NULL, create the root node.
   c. Otherwise, insert the new node at the first available position using level-order traversal with a queue.

7. Perform inorder traversal:
   a. Traverse the left subtree.
   b. Display the root data.
   c. Traverse the right subtree.

8. Perform preorder traversal:
   a. Display the root data.
   b. Traverse the left subtree.
   c. Traverse the right subtree.

9. Perform postorder traversal:
   a. Traverse the left subtree.
   b. Traverse the right subtree.
   c. Display the root data.

10. Stop.


SOURCE CODE
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node* createNode(int value) {
    node* newnode = (node*)malloc(sizeof(node));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void insert(node* root, int value) {
    node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = createNode(value);
            return;
        }
        else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = createNode(value);
            return;
        }
        else {
            queue[rear++] = temp->right;
        }
    }
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    node* root = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tree is empty\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        if (root == NULL) {
            root = createNode(value);
        }
        else {
            insert(root, value);
        }
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");

    return 0;
}


/*
Output

Enter number of nodes: 5
Enter data: 10
Enter data: 20
Enter data: 30
Enter data: 40
Enter data: 50

Inorder Traversal: 40 20 50 10 30
Preorder Traversal: 10 20 40 50 30
Postorder Traversal: 40 50 20 30 10
*/