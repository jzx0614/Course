#include <iostream>
using namespace std;
int temp[30][30]={0},count[30][30]={0};

void c(int max,int k,int l1,int l2)
{	int i,judge=0;
	if(k!=l1)
	{
		for(i=0;i<=max;i++)
		{		
			if(temp[i][l1])
			{
				c(max,k,i,l2);
			}			
		}
	}
	
	else if(k==l1&&k!=l2)
	{
		count[k][l2]++;
	}
}
int main()
{
	int n,i,j,judge=0,a=0;
	while(cin >> n)	
	{	
		for(i=0;i<30;i++)
			for(j=0;j<30;j++)
				{
					temp[i][j]=0;
					count[i][j]=0;
				}
		int max=0,j,k;
		for(i=0;i<n;i++)
		{
			cin >> j >> k;
			temp[j][k]=1;
			if(j>max)
			{max=j;}
			else if(k>max)
			{max=k;}
		}


		for(i=0;i<=max;i++)
		{	
			for(j=0;j<=max;j++)
			{
				c(max,i,j,j);
			}
		}
		cout<<"matrix for city "<<a++<<" ."<<endl;

		for(i=0;i<=max;i++)
		{
			for(j=0;j<=max;j++)
				{
					cout<<count[i][j];
				}
			cout<<endl;
		}		
	}
	return 0;
}