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




