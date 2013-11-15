#include<stdio.h>
#include<math.h>
int list[16][16];
void math(int i,int n,int k,int l)
{int x,y;
if(i>=0)
 {
  list[k-1][l-1]=n;
  i=i-1;
  x=pow(4,i);
  y=pow(2,i);
  math(i,n-(3*x),k-y,l-y);
  math(i,n-(2*x),k-y,l);
  math(i,n-x,k,l-y);
  math(i,n,k,l);
 }
}
void main()
{
 int n,i=0,j,x;
 clrscr();
 printf("Input a number(1,16,64,256):");
 scanf("%d",&n);
 j=n;i=0;x=sqrt(n);
 do{
  j=j/4;
  i++;
  }while(j>1);
 math(i,n,x,x);
for(i=0;i<x;i++)
 {
 for(j=0;j<x;j++)
    printf("%3d ",list[i][j]);
 printf("\n");
 }
 getch();
}