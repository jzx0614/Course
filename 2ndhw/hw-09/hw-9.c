#include <stdio.h>
#include <stdlib.h>
int gcd(int a , int b)
{
        return a==0 ? b : gcd(b%a,a);
}
int main(int argc,char *argv[])
{
        int m,n,lcm;
        m=atoi(argv[1]);
        n=atoi(argv[2]);
        lcm=(m*n)/gcd(m,n);
        printf("Output: %d\n",lcm);
        return 0;
}
