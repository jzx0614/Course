#include <fstream.h>
#include <iostream.h>
#include <string.h>

typedef struct link{
	char num[20],user[20],bir[20],ph[20];
	struct link *next;
}link;
link *head=NULL,*tail=NULL;

void add()
{	link *p;
	p=new link;
	cout << "\nInput a num:      "; cin>> p->num ;
	cout << "Input a user:     ";   cin>> p->user;
	cout << "Input a birthday: ";   cin>> p->bir ;
	cout << "Input a tel:	  ";    cin>> p->ph  ;
	p->next=NULL;
	if(head==NULL)
		head=p;
	else
		tail->next=p;
	tail=p;
}
void list()
{	link *p=head;
	while(p!=NULL)
	{	
		cout << endl	
			 << p->num  <<endl 
			 << p->user <<endl 
			 << p->bir	<<endl 
			 << p->ph   <<endl;
	}
}
void del()
{	
	char lookup [20];
	link *p=head,*q;
	cout << "\nInput : ";
	cin >> lookup;
	while ( p!=NULL && strcmp (p->num,lookup) )
	{	q=p;p=p->next; }
	if(p==NULL)
	{	cout << "There is no num . \n" ;}
	else if (head==p)
	{
		head=head->next;
		free(p);
	}
	else
	{q->next=p->next;}
}
void update(link *p)
{
	char lookup [20];
	cout << "\nInput : ";
	cin >> lookup;
	while ( p!=NULL && strcmp (p->num,lookup) )
		p=p->next;
	if(p==NULL)
		cout << "There is no num . \n" ;
	else 
	{	
	cout << "Input a user:     ";   cin>> p->user;
	cout << "Input a birthday: ";   cin>> p->bir ;
	cout << "Input a tel:	  ";    cin>> p->ph  ;
	}
}
void save(link *p)
{
	char file[20];
	cout << "Input a filename:";
	cin	 >> file;
	ofstream fout(file);
	while(p!=NULL)
	{	
		fout << p->num << endl;
		fout << p->user<< endl;
		fout << p->bir << endl;
		fout << p->ph  << endl <<endl;
		p=p->next;
	}
	fout.close();
}
link * op(link *head)
{
	link *p=new(link),*q;
	q=p;
	int i=0;
	char file[20],temp[20];
	cout << "Input a filename : "; cin >> file ;
	ifstream fin (file);
	if(head!=NULL) {head->next=p; }
	while(fin >> temp)
		{	
			if(i>0)
			{ 
			  p->next=new(link); 
			  p=p->next; 
			}
			strcpy(p->num,temp);
			fin >>p->user;
			fin >>p->bir ;
			fin>>p->ph;
			p->next=NULL;
			i=1;
		}	
	fin.close();
	return q;
	
}
void main(void)
{
	int choose;
	link *head=NULL,*p;	
	do{
		cout<<"\n1.Add.\n2.Delete\n3.List\n4.Update\n5.Save\n6.Open\n7.Exit\n";
		cout<<"choose 1 ~ 7 function : ";
		cin>>choose;
		switch(choose)
		{
			case 1:add();	break;
			case 2:del();	break;
			case 3:list();	break;
			case 4:update();break;
			case 5:save();	break;
			case 6:op();	break;
			default:		break;
		}
	}while(0<choose&&choose<7);
}