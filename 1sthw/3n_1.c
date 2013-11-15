#include<stdio.h>
int main()
{
 unsigned long a,b,num,i,x=0,t,count;
 while(scanf("%u %u",&a,&b)!=EOF)
 {
 x=0; 
 printf("%u %u",a,b);
 if(a>b)
	{t=a;a=b;b=t;}
 for(num=a;num<=b;num++)
	{
		i=num;
		count=1;
		while(i!=1)
		{
		if(i%2==0)
			i=i/2;
		else
			i=3*i+1;
		count++;
		}
		if(x<count)
			x=count;
	} 
	printf(" %u\n",x);
 }	return 0;
}
