#include<stdio.h>
void tower(int n,char top,char from,char aux)
{
 if(n>0)
  {
   tower(n-1,top,aux,from);
   printf("%d: from %c to %c\n",n,top,aux);
   tower(n-1,from,top,aux);
  }
}
void main()
{
 int n;
 printf("Input:");
 scanf("%d",&n);
 tower(n,'A','B','C');
}