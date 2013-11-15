#include<stdio.h>
int main()
{
 int a,judge,num=0,input,i,sum=0;
 printf("Enter a number:");
 scanf("%d",&input);
 for(i=3;i<=input;i++)
 {
  judge=1;
  for(a=2;a<i;a++)
   {
    if(i%a==0)            //耞琌Τ计
    judge=0;		  //Τ计false秈b.
   }
  if(judge==1)            //b=1借计.
  {
  printf("%d ",i);	  //陪ボ借计
  num++;		  //衡计
  sum=sum+i;		  //羆㎝
  }
 }
 printf("\n %d 借计  羆 = %d ",num,sum);
 system("pause");
}
