#include<stdio.h>
#include<conio.h>
long f(long n)
{
 if(n==1||n==2)
  return 1;
 else
  return f(n-1)+f(n-2);
}
void main()
{
 long x,ans;
 clrscr();
 printf("�п�J���p�⪺���:");
 scanf("%ld",&x);
 ans=f(x);
 printf("\n�� %ld �쬰: %ld",x,ans);
 getch();
}
