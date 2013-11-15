#include<stdio.h>
#include<conio.h>
long f(long n)
{
 if(n==0)
  return 1;
 else
  return n*f(n-1);
}
void main()
{
 long n;
 clrscr();
 printf("input a number:");
 scanf("%ld",&n);
 printf("\n%ld ! = %ld",n,f(n));
 getch();
}