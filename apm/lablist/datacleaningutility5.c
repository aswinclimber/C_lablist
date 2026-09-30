/* 
Name: Aswin K U 
Roll No: CS06
Date: 06/08/2026

Experiment No : 5
 
Heading: Data Cleaning Utility: Remove Duplicates 
 
AIM:  Create a program that takes a list of customer email addresses (stored in an array) and removes any duplicates, ensuring that each email address is only represented once.

ALGORITHM

1. Start.

2. Read the number of email addresses.

3. Read all the email addresses into an array.

4. Compare each email address with the email addresses that follow it.

5. If two email addresses are identical:
   a. Mark them as duplicate.
   b. Shift all the following email addresses one position to the left.
   c. Decrease the number of email addresses by one.
   d. Recheck the current position for further duplicates.

6. Continue the comparison until all email addresses have been checked.

7. Display the cleaned list of email addresses.

8. Stop.

SOURCE CODE
*/
#include <stdio.h>

int main(){
	int n,i,j,k;
	int same;
	printf("Enter the number of email address : ");
	scanf("%d",&n);
	char emails[n][100];
	printf("\nEnter the mails : ");
	for(i=0;i<n;i++){
		scanf("%s",emails[i]);
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			same =1;
			for(k=0;emails[i][k]!='\0' || emails[j][k]!='\0';k++){
				if (emails[i][k] != emails[j][k]){
					same = 0;
					break;
				}
			}

			if(same){
				for(k=j; k<n-1; k++){
					for (int x=0;emails[k+1][x] != '\0' || emails [k][x] != '\0'; x++){
						emails[k][x] = emails[k+1][x];
					}
				}
				n--;
				j--;
			}
		}
	}
	printf("\n cleaned mails : \n");
	for(i=0; i<n; i++){
		printf("%s\n",emails[i]);
	}
	return 0;
	

}

/*
OUTPUT

Enter the number of email address : 5

Enter the mails : 

aswinku@gmail.com

kiy@yahoo.in

aswinku@gmail.com

kiy@yahoo.in

horikita@prot.cm

cleaned mails : 

aswinku@gmail.com

kiy@yahoo.in

horikita@prot.cm
*/