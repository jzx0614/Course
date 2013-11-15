#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
void main()
{	
	char temp[100];
	cin >> temp;
	int sum=atoi(temp);
	for(int i=0;i<strlen(temp);i++)
	{		
		if(temp[i]=='+'||temp[i]=='-')
			{				
				sum=sum+atoi(temp+i);			
			}
	}
	
	cout << "sum = " << sum << endl;
}