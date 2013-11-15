#include <iostream>
using namespace std;
long long re_times;
long long fib(long n)
{
     if (n<=1) return n;
     else{ 
          re_times++;
          return fib(n-1)+fib(n-2);
     }
}
int main(){
    long long i ,F[100];
    int N,it_times=0;
    F[0]=0,F[1]=1;
    cout<< "Non Recursive:\n";
    for(i=2;i<=100;i++)
    {
        F[i]=F[i-1]+F[i-2];
        it_times++;
        if(i%10==0)
        {cout << i << "\t" << it_times <<endl;}
    }
    cout<< "\nRecursive:\n" ;
    for(i=10;i<=60;i+=10)
    {
        re_times=0;
        fib(i);
        cout<< i << "\t" <<re_times<<endl;
    }
    system("PAUSE");
    return 0;
}
