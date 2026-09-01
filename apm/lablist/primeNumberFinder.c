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
			
			
			
