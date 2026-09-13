#include <stdio.h>
#include <stdlib.h>

struct node{
    int row;
    int col;
    int value;
    struct node *next;
};

int main()
{
    int sp[10][10], i, j, r, c, count = 0;
    struct node *head = NULL, *temp, *newnode;

    printf("Enter the no of rows and columns:\n");
    scanf("%d %d",&r,&c);

    printf("Enter the matrix:\n");

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&sp[i][j]);

            if(sp[i][j] != 0)
                count++;
        }
    }

    if(r*c-count <= count){
        printf("This is not a sparse matrix\n");
        return 0;
    }

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){

            if(sp[i][j] != 0){

                newnode = (struct node*)malloc(sizeof(struct node));

                newnode->row = i;
                newnode->col = j;
                newnode->value = sp[i][j];
                newnode->next = NULL;

                if(head == NULL){
                    head = newnode;
                    temp = newnode;
                }
                else{
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }
    }

    printf("\nSparse Matrix using Linked List:\n");
    printf("Row Column Value\n");

    temp = head;

    while(temp != NULL){
        printf("%d    %d      %d\n",
               temp->row,
               temp->col,
               temp->value);

        temp = temp->next;
    }

    return 0;
}