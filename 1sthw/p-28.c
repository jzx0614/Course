#include<stdio.h>
#include<conio.h>
int f(long i)
{
 static int c=0;
 if(i!=1)
 {c++;
  printf("\n%ld",i);
  if(i%2==0)
   {
    i=i/2;
    printf("/2=%ld",i);
   }
  else
   {
    i=3*i+1;
    printf("*3+1=%ld",i);
   }
  f(i);
 }
 return c;
}
void main()
{
 long a,c;
 clrscr();
 printf("�аݥ���ƭȡG");
 scanf("%ld",&a);
 c=f(a);
 printf("\n\n�`�@����F%d��",c);
 getch();
}
