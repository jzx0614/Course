#include<stdio.h>
void main()
{
	int list[30000]={0};
	int i,j,n,c=0;

	printf("input:");
	scanf("%d",&n);
	j=n;
	
	for(i=0;i<n;i++)
		list[i]=i+1;
	for(i=0;;i++)
		{		 
		 if(i%2==0)
			 list[j++]=list[i];
		 else
			{
			 printf("%2d ",list[i]);
			 c++;
			}
		 if(c%10==0) 
			printf("\n");
		 if(c==n) 
			break;

		}
}