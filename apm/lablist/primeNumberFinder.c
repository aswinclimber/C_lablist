#include <stdio.h>
int main(){
	int n,i,j,count;
	int a[20],prime[20];
	printf("How many numbers you gonna enter : ?");
	scanf("%d",&n);

	printf("\nEnter the numbers : ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	 count = 0;
	for(i=0;i<n;i++){
		if(a[i]<2){
			continue;
		}
		int isPrime = 1;
		for(j=2;j<a[i];j++){
			if(a[i]%j==0){
				isPrime = 0;
				break;
			}
		}
		if(isPrime == 1){
			prime[count]=a[i];
			count++;
		}
	}
	printf("\nthe prime numbers : ");
	for(i=0;i<count;i++){
			printf("%d ", prime[i]);
	}
	return 0;
}
			
			
			
// ### ALGORITHM: FINDING PRIME NUMBERS FROM AN ARRAY

// 1. Start.

// 2. Read the number of elements `n`.

// 3. Read `n` numbers into the array `a`.

// 4. Initialize `count = 0`.

// 5. Traverse each element of the array.

// 6. If the number is less than `2`, skip it.

// 7. Assume the number is prime by setting `isPrime = 1`.

// 8. Check whether the number is divisible by any number from `2` up to one less than the number.

//    * If it is divisible, set `isPrime = 0` and stop checking.

// 9. If `isPrime = 1`, store the number in the `prime` array and increment `count`.

// 10. Display all the numbers stored in the `prime` array.

// 11. Stop.
