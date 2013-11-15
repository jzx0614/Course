#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
class Polynomial;
class node								//����linked list��struct
{
friend class Polynomial;
private:
	int coef,exp;						//coef���t��,exp������
	node *next;			
};

class Polynomial
{
public:
	Polynomial();						
	void storelist(int coef,int exp);	//�s�ȶilinked list���禡
	void dellist();						//�Nclass����linked list�屼.
	void read();						//�N�r�ꪺ�t�ƤΦ�����X�Ӧs�ilinked list��.
	void input();						//�@�}�l��Jp(x),s(x)����
	void write();						//�C�X�bclass����linked list
	void evaluate();					//�N�ȭp��p(x)
	void add();							//�h�����[�k
	void substract();					//�h������k
	void multiply();					//�h�������k
private:
	node *first;
	node *pos;
	node *p;							//p(x)
	node *s;							//s(x)
	
};
Polynomial::Polynomial()				//linked list ��l��
{
	first=NULL;
	pos=first;
}
void Polynomial::storelist(int coef,int exp)
{
	node *q=new node;
	q->coef=coef;						
	q->exp=exp;		
	q->next=NULL;						//������struct,�N�Ȧs�J
						
	if(first==NULL)						//�n�Olinkedlist�S��,�h��誺��first
	{	
		first=q;
		pos=q;
	}
	else								//�n�O����,�N���b�᭱
	{
		pos->next=q;
		pos=pos->next;
	}

}
void Polynomial::dellist()				//�M��class����linked list
{
	first=NULL;
	pos=first;
}
void Polynomial::read()
{
	char temp[100];
	int i,flag=0,t,y=0;
	cout << "Input a polynomial: ";		//Ū�i�r��
	cin  >> temp;
	
	for(i=1;i<strlen(temp);i++)			//�@�ӭӰ��P�_
	{
		if(atoi(temp+i-1)==0)			//���p-x x���ۦ�N�Y���ର1��-1
		{
			if(temp[i-1]=='x')t=1;		
			else t=-1;
			if(temp[i]=='^')			//�A��exp����
				y=atoi(temp+i+1);
			else
				y=1;
		}
		else 
			t=atoi(temp+i-1);	
		storelist(t,y);					//�s�Y�ƶilinked list��,������]0
		y=0;
		while((temp[i]!='+')&&(temp[i]!='-')&&(i<strlen(temp)))
		{		
			if(temp[i]=='x')			
			{	
				if(temp[i+1]=='^')		//��X�r�ꤤ������
				 pos->exp=atoi(temp+i+2);
				else
				 pos->exp=1;
			}i++;
		}flag=1;
	}	
	if(flag==0)							//��u���@�Ӧr���|�줣��,�ҥH�t�~�g
	{
		if(atoi(temp+i-1)==0)			//�u��Jx.
			storelist(1,1);
		else
			storelist(atoi(temp),0);	//�`��
	}
}
void Polynomial::input()
{
	read();
	p=first;							//Input p(x)
	dellist();
	read();
	s=first;							//Input s(x)
	dellist();
	first=p;							//�Nclass����linked list���sp(x)
}
void Polynomial::write()				//�Nclass����linked list�L�X
{
	node *t;							
	int count=0;
	for(t=first;t!=NULL;t=t->next)		//�qlist�Ĥ@�Ӷ}�l���U�j
	{	
		if(t->exp==0)					//���謰0��,�`�Ƥ��ݥ[x
		{	if(t->coef>0&&count==1)		//�����ƭn�[+��,���Ĥ@�Ӥ��ݭn
				cout<<"+"<<t->coef;		
			else
				cout<<t->coef;
		}
		else if(t->exp==1)				//���謰1��,���ݼg�X����
		{
			if(t->coef>0&&count==1)
				cout<<"+"<<t->coef<<"x";
			else
			{cout<<t->coef<<"x";count=1;}
		}
		else
		{
			if(t->coef>0&&count==1)
				cout<<"+"<<t->coef<<"x^"<<t->exp;
			else
				{cout<<t->coef<<"x^"<<t->exp;count=1;}
		}
	}		
}
void Polynomial::evaluate()
{
	int x;
	long sum=0;
	node *t;
	cout<<"\n\nInput a value: ";
	cin >> x;
	for(t=p;t!=NULL;t=t->next)
		sum+=t->coef*pow(x,t->exp);		//�Q��pow�ƾǨ禡�����N��
	cout<< "p("<<x<<")="<<sum<<"\n\n";
}

void Polynomial::add()
{	dellist();
	node *i=p,*j=s;
	while(i!=NULL&&j!=NULL)				//��p(x)��s(x)���]���Y����
	{
		if(i->exp==j->exp)				//����۵�,�Y�Ƭۥ[
		{
			storelist(i->coef+j->coef,i->exp);
			i=i->next;j=j->next;
		}
		else if(i->exp>j->exp)			//p(x)>s(x)�sp(x)�ñNp(x)���U���@�Ӳ�
		{
			storelist(i->coef,i->exp);
			i=i->next;
		}	
		else if(i->exp<j->exp)			//p(x)<s(x)�Ϥ�
		{
			storelist(j->coef,j->exp);
			j=j->next;
		}
	}
	for(;i!=NULL;i=i->next)				//��@�Ӭ�NULL��,�i���٦��t�@�ӨS�]��,
		storelist(i->coef,i->exp);		//�ҥH�t�~�ˬd,���٨S�]��,
	for(;j!=NULL;j=j->next)				//�A�s�Jlinked list
		storelist(j->coef,j->exp);
}
void Polynomial::substract()			//�h�����۴�
{
	dellist();
	node *i=p,*j=s;
	while(i!=NULL&&j!=NULL)
	{
		if(i->exp==j->exp)
		{								//�u���ܦ���ۦP,�Y�Ƭ۴�
			storelist(i->coef-j->coef,i->exp);	
			i=i->next;j=j->next;
		}
		else if(i->exp>j->exp)
		{
			storelist(i->coef,i->exp);
			i=i->next;
		}
		else if(i->exp<j->exp)
		{
			storelist(-j->coef,j->exp); //�s�J��s(x)�[�@�t��
			j=j->next;
		}
	}
	for(;i!=NULL;i=i->next)
		storelist(i->coef,i->exp);
	for(;j!=NULL;j=j->next)
		storelist(-j->coef,j->exp);		//�ѤU�Ӫ��]�O�[�t
}
void Polynomial::multiply()
{
	node *i,*j,*q,*temp1=p,*temp2=s;
	dellist();
	storelist(0,0);						//���Np(x)�]��0
	p=first;
	for(i=temp1;i!=NULL;i=i->next)		
	{	dellist();
		for(j=temp2;j!=NULL;j=j->next)	
			storelist(i->coef*j->coef,i->exp+j->exp); 
		s=first;		
		add();							//p(x)=p(x)+s(x)
		p=first;
	}
	while(p!=NULL&&p->coef!=0)			//�R���Y�Ƭ�0�����
	{	
		q=p;
		p=p->next;
	}
	if(p!=NULL)
	{
		p=q;
		free(p->next);
		p->next=NULL;
	}
	p=temp1;s=temp2;					//�Np,s�����٭�
}

int main()
{
	Polynomial c;
	c.input();
	
	cout<<"\np(x)= ";
	c.write();
	
	c.evaluate();
	
	c.add();
	cout<<"\nt(x)=p(x)+s(x)= ";c.write();cout<<endl;

	c.substract();
	cout<<"\nt(x)=p(x)-s(x)= ";c.write();cout<<endl;

	c.multiply();
	cout<<"\nt(x)=p(x)*s(x)= ";c.write();cout<<endl;

	system("PAUSE");
	return 0;
}