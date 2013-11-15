#include <iostream>
using namespace std;
int direct_tmp[9][6][6];
int direct[6][6];
int data[9];
void re(int t,int x,int lv)
{	
	int i,j,k;
	if(lv<9)
	{	
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
			direct_tmp[lv-1][i][j]=direct[i][j];
		for(i=1;i<6;i++)
		{
			if(direct[x][i]==1&&i!=x&&i!=t)
			{
				direct[x][i]=0;
				direct[i][x]=0;
				data[lv]=i;
				re(x,i,lv+1);
				
			}
			for(j=0;j<6;j++)
				for(k=0;k<6;k++)
				direct[j][k]=direct_tmp[lv-1][j][k];
		}

	}
	else
	{
		int judge=1;
		for(i=1;i<6;i++)
			for(j=1;j<6;j++)
			if(direct[i][j]==1)
			{
				judge=0;
				break;
			}
		if(judge)
		{
			for(i=0;i<9;i++)
				cout<< data[i]<< " ";
			cout << endl;
		}
	}
}
int main()
{
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
		 direct[i][j]=1;
	for(i=1;i<=2;i++)
	{
		direct[4][i]=0;
		direct[i][4]=0;
	}
	for(i=1;i<6;i++)
		for(j=1;j<6;j++)
		{
			if(i==j)
				direct[i][j]=0;
		}
	data[0]=1;
	re(0,1,1);
	return 0;
}