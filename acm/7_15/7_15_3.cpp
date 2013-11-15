#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int N,num[350]={0};
	char temp[350];
	ifstream fin ("beads.in");
	ofstream fout("beads.out");
	
	fin >> N;
	fin >> temp;

	for(int i=0;i<N;i++)
	{	char rcolor=temp[i];
		int j=i;
		if(rcolor=='w')
		{	int t=i;
			while(temp[t+1]=='w')
			{
				t++;
				if(t>=N)	{t=t%N;}
			}
			rcolor=temp[t+1];
		}
		if(rcolor=='b')
		{
			while(temp[j]!='r')
			{
				j++;
				if(j>=N){j=j%N;}
				num[i]++;				
			}
		}
		else if(rcolor=='r')
		{	while(temp[j]!='b')
			{
				j++;
				if(j>=N){j=j%N;}
				num[i]++;				
			}
		}
		
		int k=i-1,i=i+num[i];
		if(k<0){k=k+N;}
		int l=k;
		char lcolor=temp[k];
		if(lcolor=='w')
		{	int t=k; if(t<=0){t=t+N;}
			while(temp[t-1]=='w')
			{
				t--;
				if(t<=0){t=t+N;}
				
			}
			lcolor=temp[t-1];
		}
		if(lcolor=='b')
		{
			while(temp[l]!='r')
			{
				l--;
				if(l<0){l=l+N;}
				num[i]++;				
			}
		}
		else if(lcolor=='r')
		{	while(temp[l]!='b')
			{
				l--;
				if(l<0){l=l+N;}
				num[i]++;				
			}
		}
	}
	int max=num[0];
	for(i=0;i<N;i++)
	{
		if(num[i]>max)
		{max=num[i];}
	}
	fout << max <<endl;
	return 0;
}