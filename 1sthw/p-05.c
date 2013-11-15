#include<stdio.h>
void main()
{
 int a=1,x,b;
 scanf("%d",&x);
 while(a<=x)
 {
    b=1;

    while(b<=x)
     {
      if(a==b)
      printf("*");
      else
      if(a+b==x+1)
      printf("*");
      else
      printf(" ");
      b=b+1;

     }

    printf("\n");
    a=a+1;
 }
}
