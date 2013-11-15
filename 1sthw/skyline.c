#include<stdio.h>
#include<conio.h>
void main()
{
 int list[100]={0},ans[30]={0};
 int i,j=1,r,l,high,count=0,c,n;
 clrscr();
 printf("which do you input graph? ");
 scanf("%d",&n);
 do{
	printf("please input a graph: ");
	scanf("%d %d %d",&l,&high,&r);
	putchar('\n');
	count++;
	for(i=l;i<r;i++)
		{
		 if(list[i]<high)
			 {list[i]=high;}
		}
   }while(count<n);

 c=list[1];
 ans[0]=1;
 for(i=1;i<100;i++)
  {
    if(list[i]!=c)
     {
      ans[j++]=c;
      ans[j++]=i;
      c=list[i];
     }
  }
 for(i=0;i<=j;i++)
  {
   printf("%d ",ans[i]);
  }
getch();
}