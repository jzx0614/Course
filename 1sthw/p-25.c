#include<stdio.h>
#include<conio.h>
void main()
{
 int i;
 long num,t[4];
 clrscr();
 printf("請輸入秒數:");
 scanf("%ld",&num);
 for(i=0;i<2;num/=60)
  {t[i++]=num%60;}
 t[2]=num%12;
 t[3]=num/24;
 num=num/12;
 if(t[2]==0&&num%2==1)
 {t[2]=12;}
 printf("\n結果為：%ld day %ld:%ld:%ld",t[3],t[2],t[1],t[0]);
 if(num%2==0)
   printf(" AM");
 else
   printf(" PM");
 getch();
}