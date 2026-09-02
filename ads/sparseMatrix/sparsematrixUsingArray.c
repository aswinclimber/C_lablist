#include <stdio.h>

int main(){
       int sm[4][4] = {{1,0,0,0},
	       	       {0,4,0,0},
  		       {2,0,0,3},
		       {0,0,7,0}};
       int count =0,i,j;

       for(i=0;i<4;i++){
	       for(j=0;j<4;j++){
		       if(sm[i][j]!=0){
			       count++;
		       }
	       }
       }
       int opmatrix[3][count];
       for(i=0;i<3;i++){
	       for(j=0;j<count;j++){
		       for(int k=0;k<4;k++){ // for accesinng the sparx materix
              			 for(int h=0;h<4;h++){
                      			 if(sm[i][j]!=0){
						 	if(i=0){
                              					 opmatrix[i][j] = k;
							}
							else if(i=1){
								opmatrix[i][j]=h;
							}
							else if(i=2){
								opmatrix[i][j]=sm[i][j];
							 }
						 }
		      		 }
	      		 }
      		 }
       }

       printf("optimised matrix : ");
       for(i=0;i<3;i++){
              for(j=0;j<count;j++){
		printf("%d",opmatrix[i][j]);
	      }
       }
       return 0;
}



