#include<iostream.h>
#include<fstream.h>
#include<string.h>
void main(int argc,char *argv[])
{	
	
		char ch,list[300];
		int i=0;
		ifstream fin(argv[2]);
		while(!fin.eof())
		{
			fin.get(ch);
			if(!strcmp(argv[1],"en"))
				ch=ch+2;
			else if (!strcmp(argv[1],"de"))
				ch=ch-2;
            list[i++]=ch;
		}
		fin.close();
		ofstream fout(argv[2]);
		for(int j=0;j<i-1;j++)
			fout << list[j];
		fout.close();
	
}	

	


