#include<iostream>
using namespace std;
#include<stdlib.h>

long search(long *num,long key,int i,int k,int j,long n)
{
	for(int x=n-1;x>=0;x--)
	{
		if(num[x]==key)	{
			return num[x];
		}
	}
	return 0;
}



int main ()
{
	long num[1000];
	long  n;
        while(1)
	{
		cin>>n;
		if(n==0){cout<<endl;break;}
		int flag=0;	
		for(long i=0;i<n;i++)
			{cin>>num[i];}
		long sum=0;
		for(long i=n-1;i>1;i--)
		{	
			sum=num[i];
			for(long k=i-1;k>0;k--)
			{	
				if(k==i) continue;
				sum+=num[k];
				for(long j=k-1;j>=0;j--)
				{
					if(j==k||j==i) continue;	
					sum+=num[j];
						if(search(num,sum,i,k,j,n)!=0)
						{
						flag=1;
						goto answer;	
						} 
					sum-=num[j];
				}
				sum-=num[k];
			}
		}
		answer:
		if(flag==0)
		cout <<"no solution";
		else
		cout<<sum << endl; 
	}
	return 0;
}
