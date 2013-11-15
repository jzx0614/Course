#include<stdio.h>
#include<math.h>
#include<conio.h>
void main(void)
{
 int i,time[3];
 long sec[2]={0},x;
 double j;
 clrscr();

 for(i=0;i<2;i++)
  {
   printf("請輸入第%d個時間：",i+1);
   scanf("%d:%d:%d",&time[2],&time[1],&time[0]);

   for(j=0;j<3;j++)
     sec[i]+=time[j]*pow(60,j);
  }
 printf("%ld %ld\n",sec[0],sec[1]);
 if(sec[0]>=sec[1])
  x=sec[0]-sec[1];
 else
  x=sec[1]-sec[0];
 printf("%ld",x);
 for(i=0;i<=3;x/=60)
    time[i++]=x%60;
 if(x==0)
  printf("\n兩個時間的差為：%d:%d:%d",time[2],time[1],time[0]);
 getch();
}



