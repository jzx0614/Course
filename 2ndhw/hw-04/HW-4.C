#include<stdio.h>
void main()
{	
	char list[3000];
	int i=0;
	FILE *fin,*fout;
	fin=fopen("file1.txt","r");
	fout=fopen("file2.txt","w");
	do
	{
		list[i]=fgetc(fin);
	}while(list[i++]!=EOF);
i=0;
	while(list[i]!=EOF)
		fputc(list[i++],fout);
	fclose(fin);                                                           
   	fclose(fout);
}                    