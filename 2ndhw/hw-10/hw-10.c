#include<stdio.h>
#include<stdlib.h>
int gcd(int m , int n)
{
        return (m==0) ? n : gcd(n%m,m);
}
int factor(int f)
{       int i;
        for(i=1;i<=f;i++)
         if(f%i==0)
                printf(" %d",i);
        return 0;
}
int lcm(int a,int b,int c)
{
 int l=a,i=1;
 while(1)
     {
        if((l%b==0)&&(l%c==0))
                break;
        else
                l=a*(++i);
     }
 return l;
}
int main(int argc,char *argv[])
{
        int i,n[4];
        for(i=1;i<=3;i++)
                n[i-1]=atoi(argv[i]);
        printf("\nfactor = ");
        factor(gcd(gcd(n[0],n[1]),n[2]));
        printf("\n\ngcd = %d",gcd(gcd(n[0],n[1]),n[2]));
        printf("\n\nlcm = %d\n\n",lcm(n[0],n[1],n[2]));
        return 0;
}





