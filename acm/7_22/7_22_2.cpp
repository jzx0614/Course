#include<iostream>
#include<cstring>
using namespace std;
char num[25][25];
int p1(int x)
{
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			if((x+'0')==num[j][i])
			{return j;}
		}
	}
}
int p2(int x)
{
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			if((x+'0')==num[j][i])
			{return i;}
		}
	}
}
void put(int a)
{
	int x=p2(a),y=p1(a);
	for(int i=strlen(num[y])-1;i>x;i--)
	{
		num[num[y][i]-'0'][strlen(num[num[y][i]-'0'])]=num[y][i];
		num[y][i]=NULL;
	}
}
int main()
{
	int n,i;
	cin >> n;
	for( i=0;i<n;i++)
		{num[i][0]=i+'0';}		
	while(1)
	{
		char input1[5],input2[5];
		int a,b;
		cin >> input1;
		if(strcmp(input1,"quit")==0)
			break;
		cin >> a >> input2 >> b ;
	if(p1(a)!=p1(b))
	{	
		if(strcmp(input1,"move")==0)
		{
			if(strcmp(input2,"onto")==0)
			{	int x=p1(a),y=p2(a);
				put(a);	put(b);
				num[p1(b)][strlen(num[p1(b)])]=a+'0';
				num[x][y]=NULL;
			}
			else if(strcmp(input2,"over")==0)
			{	int x=p1(a),y=p2(a);
				put(a);	
				num[p1(b)][strlen(num[p1(b)])]=a+'0';
				num[x][y]=NULL;
			}
		}
		else if(strcmp(input1,"pile")==0)
		{
			if(strcmp(input2,"onto")==0)
			{
				put(b);
				int t=strlen(num[p1(a)]),s=p2(a),x=p1(a);
				for( i=p2(a);i<t+1;i++)
				{	
					num[p1(b)][strlen(num[p1(b)])]=num[x][i];
				}	
				for( i=s;i<=t;i++)
					num[x][i]=NULL;
			}
			else if(strcmp(input2,"over")==0)
			{	int t=strlen(num[p1(a)]),s=p2(a),x=p1(a);
				
				for( i=p2(a);i<=t;i++)
				{	
					num[p1(b)][strlen(num[p1(b)])]=num[x][i];					
				}
				for( i=s;i<=t;i++)
					num[x][i]=NULL;
			}
		}
	
	}
	}
		int temp[25][25];
		for(i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{temp[i][j]=num[i][j]-'0';}
		}
		
		for(i=0;i<n;i++)
		{
			cout << i <<":";
			for(int j=0;j<strlen(num[i]);j++)
			{cout<<" "<<temp[i][j];}
			cout<<endl;
		}	
	
	return 0;	
}