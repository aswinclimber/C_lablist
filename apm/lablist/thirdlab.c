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

// ### ALGORITHM: SIEVE OF ERATOSTHENES

// 1. Start.

// 2. Read the upper limit `n`.

// 3. Create a Boolean array `prime` of size `n`.

// 4. Initialize all elements of the `prime` array as `true`.

// 5. Set `prime[0]` and `prime[1]` as `false`, since 0 and 1 are not prime.

// 6. Starting from `i = 2`, check each number up to `n`.

// 7. If `prime[i]` is `true`:

//    * Consider `i` as a prime number.
//    * Start from `i × i`.
//    * Mark all multiples of `i` as `false`.

// 8. Repeat the process for all numbers.

// 9. Traverse the `prime` array and display the indices whose value is `true`.

// 10. Stop.


