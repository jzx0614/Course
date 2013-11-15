#include<iostream>
#include<fstream>
using namespace std;
int m[14][14]={0},n;
void f(int x,int y)
{	int i,j;
	if(x<=n)
	{
		for(i=1;i<=n;i++)
		{
			m[x][i]=2;	   
			m[i][y]=2;
			for(j=1;j<=n;j++)
			{
				if(x-y==i-j)
					m[i][j]=2;
				if(x+y==i+j)
					m[i][j]=2;
			}
		}	m[x][y]=1;
	
		for(i=1;i<=n;i++)
		{
		for(j=1;j<=n;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
		}
		cout<<endl;
		for(i=1;i<=n;i++)
		{	
			if(m[x+1][i]==0)
				f(x+1,i);
		}
	}
	else if(x==n)
	{
		for(i=1;i<=n;i++)
		{
		for(j=1;j<=n;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
		}
	}
}

int main()
{
	int i,j;
	ifstream fin("checker.in");
	ofstream fout("checker.out");
	cin >> n;
	//for(i=1;i<=n;i++)
	//{
		f(1,2);
	//}

	
	return 0;
}