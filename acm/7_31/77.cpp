#include <iostream>
using namespace std;
long p[500];
long t[500];
long ans[501][501];
int max(int i,int j)
{
        int x,y,sum,z=0;
        for(x=0;x<i-j+1;x++)
                {t[x]=0;}
        if(j==1)
        {
                for(x=0;x<i;x++)
                        t[0]+=p[x];
                z++;
        }
        else
        {
                for(x=j-1;x<i;x++)
                {
                        for(y=x,sum=0;y<i;y++)
                                {sum=sum+p[y];}

                        if(ans[x][j-1]<=sum)
                           t[z++]=sum;
                        else
                           t[z++]=ans[x][j-1];
                }
        }
        return z;
}
int min (int i,int j)
{
        int x,y=0,z=max(i,j);
        ans[i][j]=t[0];
        for(x=1;x<z;x++)
        {
                if(ans[i][j]>t[x])
                {
                        ans[i][j]=t[x];
                        y=x;
                }
        }
        return y;
}
int main()
{
        int data,i,j,q,m,k,x;
        long a[500];
        cin >> data;
        for(i=0;i<data;i++)
        {
                cin >> m >> k;

                for(q=0;q<m;q++)
                {
                        for(j=0;j<k;j++)
                                ans[q][j]=0;
                }
                for(j=0;j<500;j++)
                         p[j]=0;

                for(j=0;j<m;j++)
                         cin >> p[j];


                for(j=1;j<k;j++)
                {
                        for(q=1;q<m-2+j;q++)
                        {
                        if(q>=j)
                                min(q,j);
                        }
                }
                for(j=k,x=m;j>1;j--)
                {
                        a[j-2]=min(x,j)+j-1;
                        x=min(x,j)+j-1;
                }

                for(j=0,x=0;p[j]!=0;j++)
                {
                        if(a[x]==j)
                        {
                                cout<<"/ ";
                                x++;
                        }
                        cout<<p[j]<<" ";
                }
                cout <<endl;
       }
        return 0;
}
