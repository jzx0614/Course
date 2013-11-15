#include <iostream>
using namespace std;
int num[1000]={0};
int gcd (int a,int b) 
{
	return (a%b==0) ? b: gcd(b,a%b);
}
int abs(int i)
{
    return (i<0) ? i*(-1) : i;
}
int gcdall(int N)
{		int ans,i;
		ans=abs(gcd(num[0],num[1]));
		for(i=2;i<N;i++)
		{
			ans=abs(gcd(ans,num[i]));
		}
		return ans;
}
int main()
{	int n;
	while(cin >> n)
	{
		int i,N,ans=1,min;
		
		if(n!=0) {
			num[0]=n;
			min=abs(num[0]);
		}
		else	 break;

		for(i=1;n!=0;i++)
		{
			cin >>n;
			num[i]=n;
			if(min>abs(n)&&n!=0) {min = abs(n);}
		}N=i-1;
		int temp,j;
		for(i=0;i<=(min/2);i++){
			temp=gcdall(N);
			if(ans<temp){
				ans = temp;	
			}
			for(j=0;j<N;j++)
				num[j]=num[j]-1;
			
		}
		cout <<ans<<endl;
	}
	return 0;
}
