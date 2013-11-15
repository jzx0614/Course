#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	unsigned long ans[10],b[10],i,j,x;
	int cnt=0;
	ans[0]=6;
	ans[1]=35;
	for(i=2;i<10;i++)
	{
		ans[i]=ans[i-1]*6-ans[i-2];
	}
	
	for(i=0;i<10;i++)
	{	
		x=ans[i]*(ans[i]-1);
		for(j=ans[i]+1;;j++)
			if(x==(ans[i]+1+j)*(j-ans[i]))
			{
				b[i]=j;
				break;
			}
	}
	for(i=0;i<10;i++)
	{
		printf("%10lu%10lu\n",ans[i],b[i]);
	}
	
	return 0;
}