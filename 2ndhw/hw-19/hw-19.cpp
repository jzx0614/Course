#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void main(int atgc,char *argv[])
{
	ifstream fin (argv[1]);
	ofstream fout(argv[2]);
	int num=0,line=0 ,i=0;
	char list[1000];
	while( !fin.eof())
	{	fin.getline(list,sizeof(list));
	    line++;
		for(i=0;i<strlen(list);i++)
		{
			if(('a'<=list[i]&&list[i]<='z')||('A'<=list[i]&&list[i]<='Z')||('0'<=list[i]&&list[i]<='9'))
				num++;	
			if('A'<=list[i]&&list[i]<='Z')
				list[i]=list[i]+32;
		}fout << list << endl;
	}
	cout << "Line = " << line << "\nch_num = " << num ;
	
	fin.close();
	fout.close();
}