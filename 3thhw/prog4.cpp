#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
class Polynomial;
class node								//做為linked list的struct
{
friend class Polynomial;
private:
	int coef,exp;						//coef為系數,exp為次方
	node *next;			
};

class Polynomial
{
public:
	Polynomial();						
	void storelist(int coef,int exp);	//存值進linked list的函式
	void dellist();						//將class中的linked list砍掉.
	void read();						//將字串的系數及次方取出來存進linked list中.
	void input();						//一開始輸入p(x),s(x)的值
	void write();						//列出在class中的linked list
	void evaluate();					//代值計算p(x)
	void add();							//多項式加法
	void substract();					//多項式減法
	void multiply();					//多項式乘法
private:
	node *first;
	node *pos;
	node *p;							//p(x)
	node *s;							//s(x)
	
};
Polynomial::Polynomial()				//linked list 初始值
{
	first=NULL;
	pos=first;
}
void Polynomial::storelist(int coef,int exp)
{
	node *q=new node;
	q->coef=coef;						
	q->exp=exp;		
	q->next=NULL;						//先做個struct,將值存入
						
	if(first==NULL)						//要是linkedlist沒值,則剛剛的為first
	{	
		first=q;
		pos=q;
	}
	else								//要是有值,就接在後面
	{
		pos->next=q;
		pos=pos->next;
	}

}
void Polynomial::dellist()				//清掉class中的linked list
{
	first=NULL;
	pos=first;
}
void Polynomial::read()
{
	char temp[100];
	int i,flag=0,t,y=0;
	cout << "Input a polynomial: ";		//讀進字串
	cin  >> temp;
	
	for(i=1;i<strlen(temp);i++)			//一個個做判斷
	{
		if(atoi(temp+i-1)==0)			//抓到如-x x等自行將係數轉為1或-1
		{
			if(temp[i-1]=='x')t=1;		
			else t=-1;
			if(temp[i]=='^')			//再抓exp的值
				y=atoi(temp+i+1);
			else
				y=1;
		}
		else 
			t=atoi(temp+i-1);	
		storelist(t,y);					//存係數進linked list中,次方先設0
		y=0;
		while((temp[i]!='+')&&(temp[i]!='-')&&(i<strlen(temp)))
		{		
			if(temp[i]=='x')			
			{	
				if(temp[i+1]=='^')		//抓出字串中的次方
				 pos->exp=atoi(temp+i+2);
				else
				 pos->exp=1;
			}i++;
		}flag=1;
	}	
	if(flag==0)							//當只有一個字元會抓不到,所以另外寫
	{
		if(atoi(temp+i-1)==0)			//只輸入x.
			storelist(1,1);
		else
			storelist(atoi(temp),0);	//常數
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
	first=p;							//將class中的linked list先存p(x)
}
void Polynomial::write()				//將class中的linked list印出
{
	node *t;							
	int count=0;
	for(t=first;t!=NULL;t=t->next)		//從list第一個開始往下搜
	{	
		if(t->exp==0)					//當次方為0時,常數不需加x
		{	if(t->coef>0&&count==1)		//當為正數要加+號,但第一個不需要
				cout<<"+"<<t->coef;		
			else
				cout<<t->coef;
		}
		else if(t->exp==1)				//次方為1時,不需寫出次方
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
		sum+=t->coef*pow(x,t->exp);		//利用pow數學函式直接代值
	cout<< "p("<<x<<")="<<sum<<"\n\n";
}

void Polynomial::add()
{	dellist();
	node *i=p,*j=s;
	while(i!=NULL&&j!=NULL)				//當p(x)或s(x)先跑完即結束
	{
		if(i->exp==j->exp)				//次方相等,係數相加
		{
			storelist(i->coef+j->coef,i->exp);
			i=i->next;j=j->next;
		}
		else if(i->exp>j->exp)			//p(x)>s(x)存p(x)並將p(x)往下面一個移
		{
			storelist(i->coef,i->exp);
			i=i->next;
		}	
		else if(i->exp<j->exp)			//p(x)<s(x)反之
		{
			storelist(j->coef,j->exp);
			j=j->next;
		}
	}
	for(;i!=NULL;i=i->next)				//當一個為NULL時,可能還有另一個沒跑完,
		storelist(i->coef,i->exp);		//所以另外檢查,當還沒跑完,
	for(;j!=NULL;j=j->next)				//再存入linked list
		storelist(j->coef,j->exp);
}
void Polynomial::substract()			//多項式相減
{
	dellist();
	node *i=p,*j=s;
	while(i!=NULL&&j!=NULL)
	{
		if(i->exp==j->exp)
		{								//只改變次方相同,係數相減
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
			storelist(-j->coef,j->exp); //存入時s(x)加一負號
			j=j->next;
		}
	}
	for(;i!=NULL;i=i->next)
		storelist(i->coef,i->exp);
	for(;j!=NULL;j=j->next)
		storelist(-j->coef,j->exp);		//剩下來的也是加負
}
void Polynomial::multiply()
{
	node *i,*j,*q,*temp1=p,*temp2=s;
	dellist();
	storelist(0,0);						//先將p(x)設為0
	p=first;
	for(i=temp1;i!=NULL;i=i->next)		
	{	dellist();
		for(j=temp2;j!=NULL;j=j->next)	
			storelist(i->coef*j->coef,i->exp+j->exp); 
		s=first;		
		add();							//p(x)=p(x)+s(x)
		p=first;
	}
	while(p!=NULL&&p->coef!=0)			//刪掉係數為0的資料
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
	p=temp1;s=temp2;					//將p,s的值還原
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