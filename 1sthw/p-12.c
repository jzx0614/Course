#include<stdio.h>
int main(void)
{
 int a[5],i,j,t;
 for(i=0;i<=4;i++)         //input 5 number
 {
  printf("\n��J��%d�Ӽƭ�:",i+1);
  scanf("%d",&a[i]);
 }
 for(i=0;i<=4;i++)
 {  for(j=0;j<=4;j++)
   {
     if (a[i]>a[j]&&i<j)  //a[0]>a[1] a[0]>a[2]...
     {
      t=a[i];
      a[i]=a[j];          //a[i]�Ma[j]����
      a[j]=t;
     }
   }
 }
  printf("\n�Ѥp��j�ƦC��:");
  for(i=0;i<=4;i++)      //output 5 number
  printf(" %d",a[i]);
}
