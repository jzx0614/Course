//10370
//¤G¸ê¤T¥Ò  Â²§Ó°a 
#include <iostream>
using namespace std;
#include <stdio.h>

int grade[1000];

double ratio(double avg,int n)
{
	int i,count=0;
	for(i=0;i<n;i++){
		if(grade[i]>avg) count++;
	}
	return (double)count/(double)n;

}

double input()
{
	int n,total=0,i;
	double avg;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> grade[i];
		total+=grade[i];
	}
		avg=(double)total/(double)n;
		return ratio(avg,n);
}

int main()
{
	int cases;
	cin >> cases;
	for(;cases>0;cases--){
		printf("%.3f%c\n",input()*100,'%');
	}
	return 0;
}
