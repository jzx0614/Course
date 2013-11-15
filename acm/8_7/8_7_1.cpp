#include<iostream>
using namespace std;
int main()
{
	int data,sum=0,cnt,i,x=0;
	int t[100];
	while(cin>>data)
	{	
		if(data==0)
		{break;}
		sum=0;cnt=0;x++;
		for(i=0;i<data;i++)
		{
			cin>>t[i];
			sum+=t[i];
		}
		sum/=data;
		for(i=0;i<data;i++)
		{
			if(t[i]>sum)
			{
				cnt+=t[i]-sum;
			}
		}
		cout<<"Set #"<<x<<endl<<"The minimum number of moves is "<<cnt<<"."<<endl;
	}
	return 0;
}