#include<stdio.h>
#include<conio.h>
void main()
{
 int A[3][2],B[2][3],C[3][3]={0};
 int i,j,r;
 printf("input [A]:\n");
 for(i=0;i<3;i++)
 {
  for(j=0;j<2;j++)
   scanf("%d",&A[i][j]);
 }
 printf("input [B]:\n");
 for(i=0;i<2;i++)
 {
  for(j=0;j<3;j++)
   scanf("%d",&B[i][j]);
 }
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
    for(r=0;r<2;r++)
     C[i][j]+=A[i][r]*B[r][j];
 for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
    printf("%2d \t",C[i][j]);
   printf("\n");
  }
}