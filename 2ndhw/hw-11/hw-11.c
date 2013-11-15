#include<stdio.h>
	struct id
	{
		char user[20];
		char bir[20];
		char ph[20];
	};
	

void main()
{	int i;
	struct id c[3];
	printf("Input:\n");
	for(i=0;i<3;i++)
	{
		printf("User:");
		scanf("%s",&c[i].user);
		printf("\nBirthday:");
		scanf("%s",&c[i].bir);
		printf("\nPhone:");
		scanf("%s",&c[i].ph);
		printf("\n");
	}
	
	for(i=0;i<3;i++)
	{
		printf("User:%s\n\n",c[i].user);
		printf("Birthday:%s\n\n",c[i].bir);
		printf("Phone:%s\n\n",c[i].ph);
	}
}