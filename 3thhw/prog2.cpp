#include<iostream>
#include<ctime>
using namespace std;
#define Maxterm	200

class SparseMatrix
{
public:
	SparseMatrix();				//Input 一些變數的值
	void Setnonzero();			//在設定的範圍中隨機出值放入array中,並轉成一維陣列
	void listarray();			//印出二維及一維陣列
	void search(int,int);			//公式判斷位置
	
private:
	int n,a,b,Term,times;			//Term是不為0的個數,times為可隨機放數的範圍總和
	int array[Maxterm][Maxterm];		//二維陣列
	int	smarray[Maxterm*Maxterm];	//一維陣列
	
};
SparseMatrix::SparseMatrix()
{
		int i,j;
		double sparsity;			//稀疏度
		cout<<"Input n bu bl sparsity: ";
		cin>>n>>a>>b>>sparsity;				
		
		Term=sparsity*double(n*n);		//算出nonzero的數有幾個
		times=0;
		for(i=0;i<n;i++)						
		for(j=0;j<n;j++)
		{
			if(b>(i-j)&&(i-j)>(-a))		//帶狀矩陣的條件 bl bu
				times++;		//計算範圍總和
			array[i][j]=0;			//陣列歸0
		}					
}
void SparseMatrix::Setnonzero()
{
	time_t t;
	srand(time(&t));				
	int row,col,i=0;

	if(times<Term)					
	{										
		cout<<"Error Sparsity\n";		//顯示錯誤訊息並結束程式
		exit(1);
	}
	
	while(Term>0)
	{
		row=rand()%n;				//隨機出row及col
		col=rand()%n;
		if(b>(row-col)&&(row-col)>(-a)&&array[row][col]==0)				
		{					//判斷是否在帶狀矩陣中，及是否為0					
			array[row][col]=rand()%100+1;	//放入一個值		
			Term--;				//然後把Term-1
			
		}						
	}		
	int x,y;							
	for(x=0;x<n;x++)						
	for(y=0;y<n;y++)						
	if(b>x-y&&x-y>(-a))				//轉換二維中的帶狀矩陣到一維中	
		smarray[i++]=array[x][y];					
}
void SparseMatrix::listarray()				
{
	int i,j;
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		printf("%3d",array[i][j]);		//印出二維陣列
	cout<<endl;
	}
	for(i=0;i<times;i++)							
	{	
		if(i%20==0)cout<<endl;			//以20個為一行
		printf("%3d ",smarray[i]); 		//印出一維陣列
	}cout<<endl;
	
}

void SparseMatrix::search(int x,int y)
{
	if(b<=x-y||x-y<=(-a))				//判斷輸入數是否在帶狀矩陣內
	{cout<<"這數不在範圍內.\n\n";}
	else
	{						//先判斷row-1有幾個,再加上column
		int sum=0;
		if(x<b)					//前面當row小於bl時的公式,以等差導出
			sum=(2*a+(x-1))*x/2;
		else if(a>n-x+1)			//加上前面兩部分，及後面等差的部分
			sum=(2*a+(b-1))*b/2+(a+b-1)*(n-a-b+1)+(2*(a+b-2)-(x-1-((n-a)+1)))*(x-1-(n-a))/2;
		else					//中間方行的部份，加上前面的
			sum=(2*a+(b-1))*b/2+(a+b-1)*(x-b);
		
		if(x<b)					//當row<bl時，前面不為0所以+1
			sum+=y+1;
		else					//減去前面為0的個數
			sum+=y-(x-b);
		cout<<"\n這是第 "<<sum<<" 個數";
	}
}
int main()
{
	int x,y;		//x,y為row及column,flag是當布林數使用
	char t;
	SparseMatrix c;
	c.Setnonzero();
	c.listarray();
	cout<<c<<endl;
	cin>>x>>y;
	c.search(x,y);		//以公式搜尋位置


	return 0;
}