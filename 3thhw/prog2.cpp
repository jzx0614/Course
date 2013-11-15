#include<iostream>
#include<ctime>
using namespace std;
#define Maxterm	200

class SparseMatrix
{
public:
	SparseMatrix();				//Input �@���ܼƪ���
	void Setnonzero();			//�b�]�w���d���H���X�ȩ�Jarray��,���ন�@���}�C
	void listarray();			//�L�X�G���Τ@���}�C
	void search(int,int);			//�����P�_��m
	
private:
	int n,a,b,Term,times;			//Term�O����0���Ӽ�,times���i�H����ƪ��d���`�M
	int array[Maxterm][Maxterm];		//�G���}�C
	int	smarray[Maxterm*Maxterm];	//�@���}�C
	
};
SparseMatrix::SparseMatrix()
{
		int i,j;
		double sparsity;			//�}����
		cout<<"Input n bu bl sparsity: ";
		cin>>n>>a>>b>>sparsity;				
		
		Term=sparsity*double(n*n);		//��Xnonzero���Ʀ��X��
		times=0;
		for(i=0;i<n;i++)						
		for(j=0;j<n;j++)
		{
			if(b>(i-j)&&(i-j)>(-a))		//�a���x�}������ bl bu
				times++;		//�p��d���`�M
			array[i][j]=0;			//�}�C�k0
		}					
}
void SparseMatrix::Setnonzero()
{
	time_t t;
	srand(time(&t));				
	int row,col,i=0;

	if(times<Term)					
	{										
		cout<<"Error Sparsity\n";		//��ܿ��~�T���õ����{��
		exit(1);
	}
	
	while(Term>0)
	{
		row=rand()%n;				//�H���Xrow��col
		col=rand()%n;
		if(b>(row-col)&&(row-col)>(-a)&&array[row][col]==0)				
		{					//�P�_�O�_�b�a���x�}���A�άO�_��0					
			array[row][col]=rand()%100+1;	//��J�@�ӭ�		
			Term--;				//�M���Term-1
			
		}						
	}		
	int x,y;							
	for(x=0;x<n;x++)						
	for(y=0;y<n;y++)						
	if(b>x-y&&x-y>(-a))				//�ഫ�G�������a���x�}��@����	
		smarray[i++]=array[x][y];					
}
void SparseMatrix::listarray()				
{
	int i,j;
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		printf("%3d",array[i][j]);		//�L�X�G���}�C
	cout<<endl;
	}
	for(i=0;i<times;i++)							
	{	
		if(i%20==0)cout<<endl;			//�H20�Ӭ��@��
		printf("%3d ",smarray[i]); 		//�L�X�@���}�C
	}cout<<endl;
	
}

void SparseMatrix::search(int x,int y)
{
	if(b<=x-y||x-y<=(-a))				//�P�_��J�ƬO�_�b�a���x�}��
	{cout<<"�o�Ƥ��b�d��.\n\n";}
	else
	{						//���P�_row-1���X��,�A�[�Wcolumn
		int sum=0;
		if(x<b)					//�e����row�p��bl�ɪ�����,�H���t�ɥX
			sum=(2*a+(x-1))*x/2;
		else if(a>n-x+1)			//�[�W�e���ⳡ���A�Ϋ᭱���t������
			sum=(2*a+(b-1))*b/2+(a+b-1)*(n-a-b+1)+(2*(a+b-2)-(x-1-((n-a)+1)))*(x-1-(n-a))/2;
		else					//������檺�����A�[�W�e����
			sum=(2*a+(b-1))*b/2+(a+b-1)*(x-b);
		
		if(x<b)					//��row<bl�ɡA�e������0�ҥH+1
			sum+=y+1;
		else					//��h�e����0���Ӽ�
			sum+=y-(x-b);
		cout<<"\n�o�O�� "<<sum<<" �Ӽ�";
	}
}
int main()
{
	int x,y;		//x,y��row��column,flag�O���L�ƨϥ�
	char t;
	SparseMatrix c;
	c.Setnonzero();
	c.listarray();
	cout<<c<<endl;
	cin>>x>>y;
	c.search(x,y);		//�H�����j�M��m


	return 0;
}