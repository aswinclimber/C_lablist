#include<stdio.h>

#define MAX 10

void rowSum(int a[][MAX],int r,int c){

}

void columnSum(int a[][MAX], int r, int c){
}

void diagonalSum(int a[][MAX],int n){
}

void transpose(int a[][MAX], int r, int c){

}

int main(){
	int a[MAX][MAX];
	int r,c,i,j;

	printf("Enter the number of rows and columns : ");
	scanf("%d %d",&r,&c);

	printf("\nEnter the matrix elements: \n");
	for(i=0;i<r;i++){
		for(j = 0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}

        printf("\nThe matrix : \n");
        for(i=0;i<r;i++){
                for(j = 0;j<c;j++){
                        printf("%d",a[i][j]);
                }
		print("\n");
        }

	rowSum(a,r,c);
	columnSum(a,r,c);
	if(r==c){	
		diagonalSum(a,r);
	}
	else{
		printf("\n DiagonalSum requires Square Matrix");
	}

	transpose(a,r,c);

	return 0;
}



