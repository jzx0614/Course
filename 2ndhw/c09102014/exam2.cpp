#include <iostream>
#include <cstring>
using namespace std;
int f(int sum,char t[])				//1. 運算
{	int s=0;
	for(int i=0;i<strlen(t);i++)
	{
		if(t[i]=='+'||t[i]=='-')
		{
			if(t[i+1]=='(')			//3.括號
			{	
				s=atoi(t+i+2)+f(s,t+i+2);
				if(t[i]=='+')
				 sum=sum+s;
				else
				 sum=sum-s;
				while(t[i]!=')')i++;
			}
			else
				sum=sum+atoi(t+i);
		}
		else if (t[i]==')')	break;
	}	
	return sum;
}
void main()
{
	char temp[100];
	cout << "input:";
	cin	 >> temp;
	int sum=atoi(temp);
	for(int i=0;i<strlen(temp);i++)
	{	
		if((temp[i]=='+'||temp[i]=='-')&&(temp[i+1]=='+'||temp[i+1]=='-'))//2.判斷文法是否有錯
		{																  //當連續超過兩個+或-就結束
			cout << "Output: ERROR\n";
			exit(1);
		}
	}
	cout << "Output: "<< f(sum,temp) <<endl;
}