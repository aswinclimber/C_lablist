#include<stdio.h>
#include <string.h>

int isPalindrome(char code[]){
	int i = 0;
	int j = strlen(code)-1;

	while (i<j){
		if(code[i] != code[j]){
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}

int main(){
	int n, i;
	char code[100];
	printf("Enter number of product codes : ");
	if (scanf("%d",&n)!=1){
		printf("Invalid input! plese enter a integer .\n");
		return 1;
	}
	for(i=0;i<n;i++){
		printf("Enter the product code %d : ",i+1);
		scanf("%s",code);
		
		printf("product code : %s\n",code);

		if(isPalindrome(code)){
			printf("Result : Palindrome\n");
		}
		else{
			printf("Result : Not a palindrome\n");
		}
		}
	
	return 0;
}

			
