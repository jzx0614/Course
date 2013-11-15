#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
void main(int argc , char *argv[])
{
	ifstream fin (argv[1]);
	ofstream fout(argv[2]);
	char temp[100];
	while(!fin.eof())
	{
		fin.getline(temp,sizeof(temp));
		for(int i=strlen(temp)-1;i>-1;i--)
			fout <<temp[i];
		fout <<endl;
	}
	
	fin.close();
	fout.close();
}