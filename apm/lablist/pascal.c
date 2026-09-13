#include <stdio.h>

int main(){
	int n, i, j,num;
	printf("Enter number of rows : ");
	scanf("%d",&n);

	printf("pascal's Triangle : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			printf(" ");
		}

		num = 1;
		
		for(j=0;j<=i;j++){
			printf("%d ",num);
			num = num*(i-j)/(j+1);
		}
		printf("\n");
	}
	return 0;
}


// ### ALGORITHM: PASCAL'S TRIANGLE

// 1. Start.

// 2. Read the number of rows `n`.

// 3. Repeat for each row from `0` to `n-1`:

//    * Print spaces to format the triangle.
//    * Set `num = 1`.
//    * Repeat for each element in the current row:

//      * Display `num`.
//      * Calculate the next value of `num` using the Pascal's Triangle formula.

// 4. Move to the next row.

// 5. Stop.
