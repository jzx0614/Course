#include <iostream>
using namespace std;

int check1(char x)
{
	int i;
	char suit[4]={'C','D','S','H'};
	for(i=0;i<4;i++)
	{
		if(x==suit[i])
			return i;
	}
}

int check2(char x)
{
	int i;
	char suit[13]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
	for(i=0;i<13;i++)
	{
		if(x==suit[i])
			return i;
	}
}
int main()
{
	
	char t[4][2][14];
	char p[4]={'S','W','N','E'};
	char direct,x,y;
	int i,j,k,l,pe;
	while(1)
	{
		cin >> direct;
		if(direct=='#')
		{ break;	}
		for(i=0;i<4;i++)
		{
			if(direct==p[i])
				pe=i+1;	
		}
		for(i=0;i<13;i++)
		{	
			for(j=pe,l=0;l<4;j++,l++)
			{
				if(j>=4){j=j-4;}
				for(k=0;k<2;k++)
				cin >> t[j][k][i];
			}
		}
		
		for(k=0;k<4;k++)
		{
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
				{
				
					if(check1(t[k][0][j]) > check1(t[k][0][j+1]))
					{
						x=t[k][0][j];
						y=t[k][1][j];
						t[k][0][j]=t[k][0][j+1];
						t[k][1][j]=t[k][1][j+1];
						t[k][0][j+1]=x;
						t[k][1][j+1]=y;
					}
				}
			}
		}
		for(k=0;k<4;k++)
		{
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
				{
					if(check2(t[k][1][j]) > check2(t[k][1][j+1])&&t[k][0][j]==t[k][0][j+1])
					{	
						x=t[k][0][j];
						y=t[k][1][j];
						t[k][0][j]=t[k][0][j+1];
						t[k][1][j]=t[k][1][j+1];
						t[k][0][j+1]=x;
						t[k][1][j+1]=y;
					}
				}
			}
		}

		for(i=0;i<4;i++)
		{	
			cout << p[i] <<": ";
			for(j=0;j<13;j++)
			{
				for(k=0;k<2;k++)
				{	cout << t[i][k][j];}
				cout << " ";
			}cout <<endl;
		}

	}

	
	return 0;
}