 #include<stdio.h>
 int main(){
     int sp[10][10],i,j,r,c,count=0,a=0;
     printf("Enter the noof rows and columns:\n");
     scanf("%d %d",&r,&c);
     printf("Enter the matrix:\n");
     for(i=0;i<r;i++){
     	for(j=0;j<c;j++){
       		 scanf("%d",&sp[i][j]);
  }}

    for(i=0;i<r;i++){
         for(j=0;j<c;j++){
           if(sp[i][j]!=0)
             count++;
         }
    }
    a=r*c-count;
    if(a<=count){
      printf("This is not a sparse matrix\n");
      return 0;
    }
    int mat[3][count],k=0;
    for(i=0;i<r;i++){
         for(j=0;j<c;j++){
           if(sp[i][j]!=0){
                  mat[0][k]=i;
                  mat[1][k]=j;
                  mat[2][k]=sp[i][j];
                  k++;
           }
         }
    }
    printf("Matrix\n");
    for(i=0;i<3;i++){
         for(j=0;j<k;j++)
           printf("%d ",mat[i][j]);
         printf("\n");
    }
    return 0;
  }

