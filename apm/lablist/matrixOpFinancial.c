#include<stdio.h>

#define MAX 10

void rowSum(int a[][MAX], int r, int c){
	int i,j,sum;

	for(i=0;i<r;i++){
		sum = 0;
		for(j=0;j<c;j++){
			sum += a[i][j];
		}
		printf("Row %d sum : %d\n",i+1,sum);
	}
}

void columnSum(int a[][MAX], int r, int c){
	int i,j,sum;

	for(j=0;j<c;j++){
		sum = 0;
		for(i=0;i<r;i++){
			sum += a[i][j];
		}
		printf("Column %d sum : %d\n",j+1,sum);
	}
}

void diagonalSum(int a[][MAX], int n){
	int i;
	int mainSum = 0;
	int secondarySum = 0;

	for(i=0;i<n;i++){
		mainSum += a[i][i];
		secondarySum += a[i][n-1-i];
	}

	printf("Main diagonal sum : %d\n",mainSum);
	printf("Secondary diagonal sum : %d\n",secondarySum);
}

void transpose(int a[][MAX], int r, int c){
	int i,j;

	printf("\nTranspose matrix :\n");

	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			printf("%d ",a[j][i]);
		}
		printf("\n");
	}
}

int main(){
	int a[MAX][MAX];
	int r,c,i,j;

	printf("Enter the number of rows and columns : ");
	scanf("%d %d",&r,&c);

	printf("\nEnter the matrix elements: \n");

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}

	printf("\nThe matrix : \n");

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	rowSum(a,r,c);
	columnSum(a,r,c);

	if(r==c){
		diagonalSum(a,r);
	}
	else{
		printf("\nDiagonalSum requires Square Matrix\n");
	}

	transpose(a,r,c);

	return 0;
}


// ### ALGORITHM: MATRIX OPERATIONS

// 1. Start.

// 2. Declare a matrix and required variables.

// 3. Read the number of rows and columns of the matrix.

// 4. Read the elements of the matrix.

// 5. Display the matrix.

// 6. Calculate the sum of each row and display it.

// 7. Calculate the sum of each column and display it.

// 8. Check whether the matrix is square.

//    * If `rows = columns`, calculate and display the main diagonal sum and secondary diagonal sum.
//    * Otherwise, display that diagonal sum requires a square matrix.

// 9. Calculate the transpose of the matrix by interchanging its rows and columns.

// 10. Display the transpose matrix.

// 11. Stop.
