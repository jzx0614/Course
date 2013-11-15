#include<stdio.h>
void main()
{
 int num,i,a=0,sum=0;
 printf("\nenter a number:");
 scanf("%d",&num);

 for(i=2;i<=num;i+=2)
 {
  sum=sum+(a+2);
  printf("%d",a+2);

  if(a+4<=num)
    printf(",");

  a+=2;
 }
 printf("\n\ntotal=%d",sum);
}




