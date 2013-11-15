#include <iostream>
#include <cstring>
using namespace std;
int main()
{	
	char s[256];
	int i,flag,num;
	while(cin >> s)
	{	
		flag=1;
		num=0;		
		for(i=strlen(s)-1;i>=0;i--)
		{
			if(num>=2)
			{
				if(('C'<=s[i]&&s[i]<='E')||s[i]=='I')
				{
					num--;
				}
				else if('p'<=s[i]&&s[i]<='z')
				{
					num++;
				}
				else
				{
					flag=0;
					break;
				}
			}
			else if(num==1)
			{
				if('p'<=s[i]&&s[i]<='z')
				{
					num++;

				}
				else if(s[i]=='N')
				{
					num=1;
				}		
				else
				{
					flag=0;
					break;
				}
			}
			else if(num==0)
			{
				if('p'<=s[i]&&s[i]<='z')
				{
					num++;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}  
		if(num==2)
		{
			flag=0;
		}
		if(flag==1)
		{ cout<<"YES"<<endl;}
		else
		{ cout<<"NO"<<endl;}
	}
	return 0;
}