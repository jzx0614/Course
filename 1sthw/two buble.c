#include<stdio.h>
#include<conio.h>
void swap(int list[],int i,int j)
{
 int tmp;
 tmp=list[i];
 list[i]=list[j];
 list[j]=tmp;
}
void main()
{
 int i,j,l=5,r=0,a[]={8,50,64,20,79,25};
 clrscr();
 for(i=0;i<5;i++)
  {
   for(j=r;j<l-1;j++)
    {if(a[j]>a[j+1])
     swap(a,j,j+1);
    }l--;
   for(j=l;j>r+1;j--)
    {
    if(a[j+1]<a[j])
     swap(a,j+1,j);
    }r++;
  }
 for(i=0;i<6;i++)
  printf("%d \t",a[i]);
 getch();
}
