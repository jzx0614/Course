#include <iostream>
using namespace std;
int main()
{
	int data,x=0;
	cin >> data;
	int count[1000]={0};
	while(data>0)
	{
		int n,i,j;
		cin >> n;
		int *num = new int[n];
		for(i=0;i<n;i++)
			cin >> num[i];
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1;j++)
			{ 
				if(num[j]>num[j+1])
				{
					int t;
					t=num[j];
					num[j]=num[j+1];
					num[j+1]=t;
					count[x]++;
				}
			}
		}
		x++;
		data --;
	}
	for(int i=0;i<x;i++)
	{cout << "Optimal train swapping takes "<<count[i]<<" swaps." << endl;}
	
	return 0;
}