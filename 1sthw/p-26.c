#include<stdio.h>
#include<conio.h>
int f(int);
void main()
{
 int day,high;
 clrscr();
 textcolor(GREEN);
 cprintf("\n�аݿ�J���� :");
 scanf("%d",&high);
 day= f(high);
 textcolor(YELLOW);
 cprintf("\n�����ݭn�� %d �Ѥ~�દ�X��",day);
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
