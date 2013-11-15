#include<iostream>
using namespace std;
#define Max 50
int flag=0;
class offsets
{
public:
	int x,y;
};
class Knight
{
public:
	Knight(int n,int m,int x,int y);
	void push(int x,int y);
	void pop();
	void priority(int x,int y);
	void path(int x,int y,int n);	
	void Getarray();

private:
	int N,M,top;
	int array[Max][Max];
	int direct[8];
	offsets move[8];
	offsets *stack;
};

Knight::Knight(int n,int m,int x,int y)
{
	N=n;M=m;
	stack=new offsets[N*M];
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)
			array[i][j]=0;
	top=-1;
	push(x,y);
	array[x][y]=1;
	
	int temp[8]={1,2,2,1,-1,-2,-2,-1};
	for(i=0;i<8;i++)
	{
		move[i].x=temp[i];
		move[i].y=temp[(i+6)%8];
	}
}
void Knight::push(int x,int y)
{
	stack[++top].x=x;
	stack[top].y=y;
}
void Knight::pop()
{
	stack[top].x=0;
	top--;
}
void Knight::priority(int x,int y)
{
	int temp[8]={0};
	for(int i=0;i<8;i++)
	{
		int times=0;
		for(int j=0;j<8;j++)
		{
			int g=x+move[i].x+move[j].x;
			int h=y+move[i].y+move[j].y;
			if(0<g&&g<=N&&0<h&&h<=M&&array[g][h]==0)
			{
				temp[i]=times++;
			}
		}
	}
	int t;
	for(i=0,t=0;i<=8;i++)
	for(int j=0;j<8;j++)
		if(temp[j]==i)
		{	direct[t++]=j; }
}
void Knight::path(int x,int y,int n)
{
	if(n==0)
	{	
		Getarray();
		exit(1);
	}
	else
	{
		priority(x,y);
		for(int i=0;i<8;i++)
		{
			int g=x+move[direct[i]].x,h=y+move[direct[i]].y;
			if(0<g&&g<=N&&0<h&&h<=M&&array[g][h]==0)
			{
				push(g,h);
				array[g][h]=N*M-n+1;
				path(g,h,n-1);
			}
		}
		pop();
		array[x][y]=0;
	}

}
void Knight::Getarray()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			printf("%4d",array[i][j]);
		cout<<"\n";
	}
	for(i=0;i<=top;i++)
		printf("(%2d,%2d) ",stack[i].x,stack[i].y);	
	flag=1;
	system("PAUSE");
}
int main()
{
	int n,m,x,y;
	cout<<"Input n,m,x,y: ";
	cin >> n >> m >> x >> y ;
	Knight r(n,m,x,y);
	r.path(x,y,n*m-1);
	if(flag==0)
	{
		cout<<"There is no solution\n";
		system("PAUSE");
	}
	
	return 0;
}