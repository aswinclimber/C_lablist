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

			
// ### ALGORITHM: PRODUCT CODE PALINDROME CHECKER

// 1. Start.

// 2. Define a function `isPalindrome()` to check whether a product code is a palindrome.

// 3. Read the number of product codes `n`.

// 4. If the input for `n` is invalid, display an error message and terminate.

// 5. Repeat the following steps for each product code:

//    * Read the product code.
//    * Display the product code.
//    * Set `i = 0` and `j = length of code - 1`.
//    * Compare the characters at positions `i` and `j`.
//    * If they are different, return **Not a Palindrome**.
//    * Increment `i` and decrement `j`.
//    * Continue until `i >= j`.

// 6. If all corresponding characters are equal, return **Palindrome**.

// 7. Display the result for each product code.

// 8. Stop.
