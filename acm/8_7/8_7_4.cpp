#include<stdio.h>
#include<string.h>
int main()
{
	char input[101][101];
	int i=0,j,x,rmax=0,lmax=0;

	for(j=0;scanf("%c",&input[lmax][j])!=EOF;j++)
	{	
		if(input[lmax][j]=='\n')
		{
			if(j>rmax)
			{
				rmax=j;
				input[lmax][j]=' ';
				input[lmax][j+1]='\0';
			}
			else if(j<rmax)
			{
				for(x=j;x<rmax;x++)
					input[lmax][x]=' ';
				input[lmax][x+1]='\0';
			}
			lmax++;
			j=-1;
			
		}
	}
	for(i=0;i<rmax;i++)
	{
		for(j=lmax-1;j>=0;j--)
		{printf("%c",input[j][i]);}
		printf("\n");
	}


	return 0;
}