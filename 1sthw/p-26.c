#include<stdio.h>
#include<conio.h>
int f(int);
void main()
{
 int day,high;
 clrscr();
 textcolor(GREEN);
 cprintf("\n請問輸入高度 :");
 scanf("%d",&high);
 day= f(high);
 textcolor(YELLOW);
 cprintf("\n蝸牛需要花 %d 天才能爬出來",day);
 getch();
}
int f(int x)
{
 int i=0,high=0;
 while(high<x)
 {
  high=high+3;
  if(high<x)
   high=high-1;
  i++;
 }
 return i;
}
