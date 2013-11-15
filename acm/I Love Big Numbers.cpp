#include <iostream>
using namespace std;

int main(void)
{
	int num[50000];
	int i,j,temp,ans[1001]={0};
	for(i=1;i<50000;i++)
		num[i]=0;
	num[0]=1;
	for(i=1;i<=1000;i++){
		for(j=0;j<50000;j++)
			num[j]*=i;
		for(j=0;j<49999;j++)
		{
			num[j+1]+=num[j]/10;
			num[j]=num[j]%10;
		}
		for(temp=0,j=0;j<50000;j++){
			temp+=num[j];
		}
		ans[i]=temp;
	}	
	int n;
	while(cin >> n)
	{
		cout<<ans[n]<<endl;
	}
}
