//575
//¤G¸ê¤T¥Ò  Â²§Ó°a 
#include<iostream>
using namespace std;
#include<string.h>
#include<math.h>
int main(void){
    unsigned long number=0,i,num[80];
    char buff[80];
    while(cin >> buff)
    {
        if(buff[0]=='0') break;
        for(i=0;i<strlen(buff);i++)
                num[strlen(buff)-i-1]=buff[i]-'0';
        number=0;
        for(i=0;i<strlen(buff);i++)
                number+=(unsigned long)(pow((double)2,(double)(i+1))-1)*num[i];

        cout<<number<<endl;
    }
}
