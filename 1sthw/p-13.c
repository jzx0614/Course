#include<stdio.h>
void main()
{
 int a[9],i,t;
 for(i=0;i<=1;i++)
 {
  printf("\nEnter a number:");
  scanf("%d",&a[i]);
 }

 if(a[0]>a[1])
  {t=a[0];a[0]=a[1];a[1]=t;}

 for(i=0;i<=8;i++)
 {
  if(i>=2)
  a[i]=a[i-1]+a[i-2];
  printf("%d ",a[i]);
 }
}