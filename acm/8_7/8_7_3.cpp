#include<stdio.h>
int main()
{
	long r,l,i,t,x,max,cnt;
	while(scanf("%ld %ld",&r,&l)!=EOF)
	{
		printf("%u %u ",r,l);
		if(r>l)
		{x=r;r=l;l=x;}
		max=0;
		for(i=r;i<=l;i++)
		{
			t=i;cnt=0;
			while(t>1)
			{
				if(t%2==1)
					t=3*t+1;
				else
					t=t/2;
				cnt++;
			}
			if(max<cnt)
			{max=cnt;}
		}		
		printf("%u\n",max+1);
	}
	return 0;
}