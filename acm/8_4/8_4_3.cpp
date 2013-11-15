#include <iostream>
#include <cmath>
using namespace std;
#include <stdio.h>
int gcd(int a,int b)
{ 
	return a==0 ? b : gcd(b%a,a);
}
int main()
{
	double c1,c2;
	int data,i,j;
	int ans[51];
	while(cin >> data)
	{
		if (data==0)
			break;
		for(i=0;i<data;i++)
			cin >> ans[i];
		c1=0;c2=0;
		for(i=0;i<data;i++)
		{
			for(j=0;j<data;j++)	
			{
				if(i<j)
				{
					c2++;
					if(gcd(ans[i],ans[j])==1)
						c1++;				
				}
			}
		}
		
		if(c1==0)
			cout<<"No estimate for this data set."<<endl;
		else
			printf("%f\n",sqrt(6*c2/c1));
		
		for(i=0;i<data;i++)
			ans[i]=0;
	}
	
	return 0;
}