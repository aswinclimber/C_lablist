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



