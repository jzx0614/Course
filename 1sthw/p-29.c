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
 printf("請輸入欲計算的位數:");
 scanf("%ld",&x);
 ans=f(x);
 printf("\n第 %ld 位為: %ld",x,ans);
 getch();
}
