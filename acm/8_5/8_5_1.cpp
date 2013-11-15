#include <iostream>
using namespace std;
int main()
{
	int k,n,i,j,l,t;
	int ans[11][30];
	int dp[30]={1};
	while(cin>>k>>n)
	{
		for(i=0;i<k;i++)	
		{
			for(j=1;j<=n;j++)
				cin>>ans[j][i];
			ans[0][i]=i+1;
		}
		
		for(i=0;i<k;i++)	
		{	for(j=0;j<n-1;j++)
				for(l=1;l<n;l++)
					if(ans[l][i]>ans[l+1][i])
					{
						t=ans[l][i];
						ans[l][i]=ans[l+1][i];
						ans[l+1][i]=t;
					}
		}
		for(j=0;j<k-1;j++)
				for(l=0;l<k-1;l++)
					if(ans[1][l]>ans[1][l+1])
					{
						for(i=0;i<=n;i++)
						{
							t=ans[i][l];
							ans[i][l]=ans[i][l+1];
							ans[i][l+1]=t;
						}
					}

		for(i=0;i<k;i++)
			{dp[i]=1;}
		
		
		for(i=1;i<k;i++)
		{
			for(j=0;j<i;j++)
			{
				if(ans[2][j]<ans[2][i])
					if(dp[i]<=dp[j])
						dp[i]=dp[j]+1;
			}
		}
		for(i=0;i<k;i++)
		{cout<<dp[i]<<"\t";}
		cout<<endl;
		for(i=0;i<=n;i++)	
		{
			for(j=0;j<k;j++)
				cout<<ans[i][j]<<"\t";
			cout<<endl;
		}			
	}
	return 0;
}