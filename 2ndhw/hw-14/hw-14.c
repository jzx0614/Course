#include<stdio.h>
int f(int x)
{
	if(x==0)
		return 0;
	else if(x%2==0)
		return 2*f(x-1);
	else
		return 2*f(x-1)+1;
}

void main()
{	int num;
	do{	
	printf("Input a num: ");	
	scanf("%d",&num);	
	}while(num<1);
	printf("X(%d) = %d\n",num,f(num));
}