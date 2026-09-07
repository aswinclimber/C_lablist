 #include<stdio.h>
 nt main(){
  3   int sp[10][10],i,j,r,c,count=0,a=0;
  4   printf("Enter the noof rows and columns:\n");
  5   scanf("%d %d",&r,&c);
  6   printf("Enter the matrix:\n");
  7   for(i=0;i<r;i++){
  8     for(j=0;j<c;j++)
  9       scanf("%d",&sp[i][j]);
  }
    for(i=0;i<r;i++){
         for(j=0;j<c;j++){
           if(sp[i][j]!=0)
             count++;
         }
    }
 17   a=r*c-count;
 18   if(a<=count){
 19     printf("THis is not a sprae matrix\n");
 20     return 0;
 21   }
 22   int mat[3][count],k=0;
 23   for(i=0;i<r;i++){
 24        for(j=0;j<c;j++){
 25          if(sp[i][j]!=0){
 26                 mat[0][k]=i;
 27                 mat[1][k]=j;
 28                 mat[2][k]=sp[i][j];
 29                 k++;
 30          }
 31        }
 32   }
 33   printf("Matrix\n");
 34   for(i=0;i<3;i++){
 35        for(j=0;j<k;j++)
 36          printf("%d ",mat[i][j]);
 37        printf("\n");
 38   }
 39   return 0;
 40 }

