#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char *t[]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
	char temp1[2],temp2[2],temp3[2] ;
	char tmp[3][3];
	
	int i=0,num[3]={0},j[2],x=0;
	
	
	cin >> temp1 ;
	cin >> temp2 ;
	cin >> temp3 ;
	
	cout << temp1<<" ";
	cout << temp2<<" ";
	cout << temp3;
	
	

	if('a'<=temp1[0]&&temp1[0]<='z'){temp1[0]=temp1[0]-32;}
	if('a'<=temp2[0]&&temp2[0]<='z'){temp2[0]=temp2[0]-32;}
	if('a'<=temp3[0]&&temp3[0]<='z'){temp3[0]=temp3[0]-32;}
	
	if(temp1[1]=='b'){temp1[0]=temp1[0]-1;temp1[1]='#';}
	if(temp2[1]=='b'){temp2[0]=temp2[0]-1;temp2[1]='#';}
	if(temp3[1]=='b'){temp3[0]=temp3[0]-1;temp3[1]='#';}

	strcpy(tmp[0],temp1);
	strcpy(tmp[1],temp2);
	strcpy(tmp[2],temp3);

	while(strcmp(temp1,t[i++])){num[0]++;} i=0;
	while(strcmp(temp2,t[i++])){num[1]++;} i=0;
	while(strcmp(temp3,t[i++])){num[2]++;} i=0;
	


	for(i=0;i<3;i++)
	{
		int a,b,c;
		a=i;
		if(i+1>=3){b=(i+1)%3;}
		else{b=(i+1);}
		if(i+2>=3){c=(i+2)%3;}
		else{c=(i+2);}
		

		j[0]=num[b]-num[a];
		j[1]=num[c]-num[b];
		if(j[0]<0){j[0]=j[0]+12;}
		if(j[1]<0){j[1]=j[1]+12;}


		if(j[0]==4&&j[1]==3)
		{cout  << " is a "<<tmp[i]<<" Major chord." << endl;x++;}
		else if(j[0]==3&&j[1]==4)
		{cout  << " is a "<<tmp[i]<< " Minor chord."<< endl;x++;}
	}
	if (x==0)
	{cout <<" is unrecognized."<<endl;}
	
	return 0;
}


