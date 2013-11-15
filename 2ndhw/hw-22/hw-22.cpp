#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class bank
{
 public:
	bank(int=0);
	~bank();
	void List();
	void Deposit();
	void Draft();
	
 private:
	int money;
};
int input()
{
	char temp[20];
	int judge=0,i;
	do{
	 cout<< "Input a num : ";
	 cin >> temp;
	 judge=0;
	 for(i=0;i<strlen(temp);i++)
	 {
		if('0'<=temp[i]&&(temp[i]<='9'))
			judge=0;
		else
		{       judge=1;
			cout << "Error a num:\n ";
			break;
		}
	 }
	}while(judge!=0);

	return atoi(temp);
}
bank::bank(int m){money=m;}
bank::~bank(){cout << "over";}
void bank::List ()
	{cout << "You have " << money << " in the bank\n";}
void bank::Deposit()
{       money=money+input(); }
void bank::Draft ()
{    int p;
     p=input();
     if(money>=p)
	money=money-p;
     else
	cout <<"\n error a num. \n";
}

void main()
{
	int choose;
	class bank t;
	do{
	cout << "1.List.\n2.Deposit.\n3.Draft.\n4.Exit\nplease input a function: " ;
	cin  >> choose;
	switch(choose)
	 {
	  case 1:t.List();break;
	  case 2:t.Deposit();break;
	  case 3:t.Draft();break;
	 }
	}while(0<choose&&choose<4);
}

