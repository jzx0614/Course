#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
 time_t t;
 int l,r,i,j,e,judge,num[10000]={0},sum=0,x=0,y=0;
 srand(time(&t));

 l=rand()%100+1;
 r=rand()%100+1;
 printf("\n\n1.(x,y)=(%d,%d)\n\n",l,r);

 if(l>r)
  {
   e=l;l=r;r=e;
  }
 delay(2000);
 printf("2.计Τ:");
 for(i=l;i<=r;i++)
 {
  if(i%2==1)
   printf(" %d",i);
 }
 delay(2000);
 printf("\n\n3.借计Τ:");

 for(i=l;i<=r;i++)
  {
  judge=1;

   for(j=2;j<i;j++)
   {
    if(i%j==0)
     judge=2;
   }
    if (judge==1)
     {
      printf(" %d",i);
      y++;
     }

  }
  if(y==0)
  printf("⊿Τ借计");
  delay(2000);
  printf("\n\n4.Ч计Τ:");

  for(i=l;i<=r;i++)
  {
  sum=0;
   for(j=1;j<i;j++)
    {
     if(i%j==0)
      sum=sum+j;
    }

   if(i==sum)
    {
     printf(" %d",i);
     x++;
    }
   }
   if(x==0)
    printf("⊿ΤЧ计");

  getch();
}
