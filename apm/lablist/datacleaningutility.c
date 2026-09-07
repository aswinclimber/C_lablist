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
