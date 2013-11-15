#include <iostream>
using namespace std;
int main(void){
    long long num[50000];
    long n;
    num[0]=1;
    for(long long i=1;i<50000;i++)
    {
        num[i]=num[i-1]+((i+1)*(i+1)*(i+1));
    }
    while(cin >> n)
    {
        cout<<num[n-1]<<endl;
    }
}
