#include<iostream>
using namespace std;
char data[9],data_tmp[9];

void re(int lv,int n)
{	int i,j,t;
	if(lv!=n)
	{	
		t=strlen(data);
		data_tmp[t+1]='\0';
		for(i=0;i<=lv;i++)
		{			
			for(j=t;j>=i;j--)
			{
				data_tmp[j]=data[j-1];
			}
			data_tmp[i]=lv+'a';
			re(lv+1,n);
		}
	}
	else
	{
		for(i=0;i<=lv;i++)
			cout<<data_tmp[i];
		cout<<endl;
	}
}
int main()
{
	data[0]='a';
	data_tmp[0]='a';
	int n;
	cin >> n;
	re(1,n);
	return 0;
}