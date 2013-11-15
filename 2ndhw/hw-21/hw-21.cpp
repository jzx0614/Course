#include<iostream>
#include<cstring>
using namespace std;
void change( char num[20],int t)
{	int x=t;
	for(int i=0;i<t;i++)
	{	
		if(num[i]=='0'&&num[i+1]!='0'&&num[i+1]!='\0')
		 {cout << "¹s" ; }
		switch (num[i])
		{		 
			case '1': cout << "³ü" ;break;
			case '2': cout << "¶L" ;break;
			case '3': cout << "°Ñ" ;break;
			case '4': cout << "¸v" ;break;
			case '5': cout << "¥î" ;break;
			case '6': cout << "³°" ;break;
			case '7': cout << "¬m" ;break;
			case '8': cout << "®Ã" ;break;
			case '9': cout << "¨h" ;break;					
		}
 
	    if(num[i]!='0')
		 {
	      switch (x)
		  {
			case 2: cout << "¬B" ; break;
			case 3: cout << "¨Õ" ; break;
			case 4: cout << "¥a" ; break;
			case 5: cout << "¸U" ; break;
			case 6: cout << "¬B" ; break;
			case 7: cout << "¨Õ" ; break;
			case 8: cout << "¥a" ; break;
		  } 
		}x--;
	}
}
void main()
{
	char temp[10];
	cout << "Input:";
	cin  >> temp;

	change(temp,strlen(temp));
}