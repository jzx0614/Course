#include<stdio.h>
#include<conio.h>
#include<string.h>
void swap(char *p,char *q)
{
	char tmp;
	tmp=*p;
	*p=*q;
	*q=tmp;
}

void main()
{
	char a[10],b[10],list[20],list2[20];
	int i,j,count,judge;
	clrscr();
	printf("input 1 string:");
	scanf("%s",a);
	printf("input 2 string:");
	scanf("%s",b);

	/********************** 1 . ********************/

	strcpy(list,a);
	strcat(list,b);
	strcpy(list2,list);
	printf("\n1. %s\n",list);

	/********************** 2 . ********************/
		count=strlen(list);
		printf("2. ");
	for(i=count-1;i>=0;i--)
		printf("%c",list[i]);

	/********************** 3 . ********************/

	for(i=0;i<count-1;i++)
	 for(j=0;j<count-1;j++)
		if(list[j]>list[j+1])
			swap(&list[j],&list[j+1]);
	printf("\n3. %s\n",list);

	/********************** 4 . ********************/

	printf("4. ");
	for(i=0;i<count;i++)
	{       judge=1;
		for(j=0;j<i;j++)
		 {
			if(list2[i]==list2[j])
			{
			 judge=0;
			 break;
			}
		 }
		if(judge)
			printf("%c",list2[i]);
	}
	getch();
}
