#include <stdio.h>
#include <conio.h>
#include <math.h>
long isArmstrongNumber(long x)
{
 double y;
 long t[10]={0},i=0,sum=0;


 for(;x!=0;x/=10)
  {t[i++]=x%10;}

 y=i;
  printf("\n");
 for(i=i-1;i>=0;i--)
  {
   if(i>0)
    printf(" %ld^%.f +",t[i],y);
   else
     printf(" %ld^%.f =" ,t[i],y);
   sum=sum+pow(t[i],y);
  }
   printf(" %ld",sum);
 return sum;

}
void main()
{
 long num,ans;
 clrscr();
 printf("請輸入一個正整數:");
 scanf("%ld",&num);
 ans=isArmstrongNumber(num);

 if(ans==num)
  printf(" 是阿姆斯壯數");
 else
  printf(" 不是阿姆斯壯數");

 getch();
}