//10222
//¤G¸ê¤T¥Ò  Â²§Ó°a 
#include <stdio.h>
#include<ctype.h>
int main()
{
	char encode[45]="234567890-=\\ertyuiop[]dfghjkl;'cvbnm,./" ;
	char decode[45]="`1234567890-qwertyuiopasdfghjklzxcvbnm," ;

	char ch;
	int i;
	while(scanf("%c",&ch)==1){
		ch=tolower(ch);
		
		for(i=0;i<45;i++){
			if(ch==encode[i]){
				putchar(decode[i]);
				break;
			}
		}
			if(i==45)
				putchar(ch);
	}
	return 0;
}
