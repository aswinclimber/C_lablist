/* 
Name: Aswin K U 
Roll No: CS06
Date: 29/07/2026
 
******** Efficient Prime Number Generation ******** 
 
AIM: Implement the Sieve of Eratosthenes algorithm to generate a list of prime numbers up to a specified upper limit (e.g., 10,000). This list will be used for efficient lookups in a mathematical application.

ALGORITHM

1. Start.

2. Read the upper limit `n`.

3. Create a Boolean array `prime` of size `n`.

4. Initialize all elements of the `prime` array as `true`.

5. Set `prime[0]` and `prime[1]` as `false`, since 0 and 1 are not prime.

6. Starting from `i = 2`, check each number up to `n`.

7. If `prime[i]` is `true`:
   * Consider `i` as a prime number.
   * Start from `i × i`.
   * Mark all multiples of `i` as `false`.

8. Repeat the process for all numbers.

9. Traverse the `prime` array and display the indices whose value is `true`.

10. Stop.

SOURCE CODE
*/
#include <stdio.h>
#include <stdbool.h>
int main(){
	int n,i,j;
	printf("Enter the upperlimit : \n");
	scanf("%d",&n);
	bool prime[n];
	for(i=0;i<n;i++){
		prime[i]=true;
		}
	prime[0]=false;
	prime[1]=false;
	for(i=2;i<=n;i++){
		if (prime[i]){
			for(j=i*i;j<=n;j+=i){
			prime[j]=false;
		}
		}
	}
	printf("The prime numbers : ");
	for(i=0;i<n;i++){
		if (prime[i]){
			printf("%d",i);
			printf(" ");
		}
	}
	return 0;

}

/*
OUTPUT

Enter uppper limit:100

The prime numbers : 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
*/


