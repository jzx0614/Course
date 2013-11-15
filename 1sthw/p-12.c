#include<stdio.h>
int main(void)
{
 int a[5],i,j,t;
 for(i=0;i<=4;i++)         //input 5 number
 {
  printf("\n輸入第%d個數值:",i+1);
  scanf("%d",&a[i]);
 }
 for(i=0;i<=4;i++)
 {  for(j=0;j<=4;j++)
   {
     if (a[i]>a[j]&&i<j)  //a[0]>a[1] a[0]>a[2]...
     {
      t=a[i];
      a[i]=a[j];          //a[i]和a[j]互換
      a[j]=t;
     }
   }
 }
  printf("\n由小到大排列為:");
  for(i=0;i<=4;i++)      //output 5 number
  printf(" %d",a[i]);
}
