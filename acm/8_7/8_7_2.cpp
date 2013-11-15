#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
int main()
{
	int i,cnt=1;
	char t[1000];
	while(gets(t))
	{
		for(i=0;i<strlen(t);i++)
		{
			if(t[i]=='"')
			{
				if(cnt%2==1)
					cout<<"``";
				else
					cout<<"''";
				cnt++;
			}
			else
				cout<<t[i];
		}
		cout<<endl;
	}
	return 0;
}