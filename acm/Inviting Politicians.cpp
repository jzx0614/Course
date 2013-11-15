#include <iostream>
using namespace std;

int main()
{
	int testtime;
	
	cin >>testtime;
	for(int p=0;p<=testtime;p++)
	{
		int n,m,i,j,x,y;
		int buff[301],d[301][301];
		char namelist[11][301];
		cin >> n >> m;
		for(i=0;i<n;i++)		
		{
			buff[i]=1;
			cin>>namelist[i];
		}
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			for(j=0;j<n;j++)
				if()
		}
		for(i=0;i<n;i++)
		{
			cout<<namelist[i]<<endl;
		}
	}
	return 0;
}