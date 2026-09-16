#include<stdio.h>
#include<ctype.h>

int main(){
	char str[20];
	int i;
	printf("Enter a string : ");
	fgets(str,sizeof(str),stdin);

	for(i=0;str[i]!='\0';i++){
		str[i] = tolower(str[i]);
		switch(str[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				printf("\n%c : Vowel \n",str[i]);
				break;
			default :
				if((str[i]>='a'&& str[i]<='z')){
					printf("\n%c : consonant\n",str[i]);
				}
				else{
					printf("\n%c : Other\n",str[i]);
				}
		}
	}
	return 0;
}




// ALGORITHM: VOWEL AND CONSONANT IDENTIFICATION

// 1. Start.

// 2. Declare a character array to store the input string.

// 3. Read the string from the user.

// 4. Traverse the string character by character.

// 5. Convert each character to lowercase.

// 6. Check whether the character is a vowel:
//       a. If the character is 'a', 'e', 'i', 'o', or 'u',
//          display "Vowel".
//       b. Otherwise, check whether the character is an alphabet.

// 7. If the character is an alphabet, display "Consonant".

// 8. If the character is not an alphabet, display "Other".

// 9. Repeat the process until the end of the string is reached.

// 10. Stop.
