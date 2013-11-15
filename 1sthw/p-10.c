#include<stdio.h>
void main()
{
 int a[15],num,i=0;
 printf("\nEnder a number:");
 scanf("%d",&num);
  for(;num>=1;num/=2)
   a[i++]=num%2;
  while(--i>=0)
   printf("%d",a[i]);
   system("pause");
}
