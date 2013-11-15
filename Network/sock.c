#include <winsock.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define BUFLEN 100
   
int main(int argc,char *argv[])
{
    FILE *fin;

    int clientSock,msgLen;
    int i,j,sign,num,x=-1,port;
    
    long n_total;
	unsigned long p_total;

    struct sockaddr_in serverAddr;
    
    char in_buf[BUFLEN];
    char temp[]={"C09102014_jzx.txt"};
    char string[12];
    char ip[16];

    WSADATA wsaData;
    WSAStartup(MAKEWORD(1,1),&wsaData);
	
	printf("Input IP Address : ");
	scanf("%s",ip);
	printf("Input Port Number: ");
	scanf("%d",&port);
	
    if((clientSock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==INVALID_SOCKET){
        puts("CLIENT: socket() error.");
        exit(1);
    }

	memset((char *)&serverAddr,'\0',sizeof(struct sockaddr_in));

    serverAddr.sin_family=AF_INET;
//    serverAddr.sin_addr.s_addr=inet_addr("140.126.5.15");    
//    serverAddr.sin_port=htons(30000);]
//    serverAddr.sin_addr.s_addr=inet_addr("140.126.4.215");    
//    serverAddr.sin_port=htons(3176);
    serverAddr.sin_addr.s_addr=inet_addr(ip);    
    serverAddr.sin_port=htons(port);

	if(connect(clientSock,(struct sockaddr *)&serverAddr,sizeof(struct sockaddr_in))==SOCKET_ERROR){
		puts("CLIENT:	connect() error.");
		closesocket(clientSock);
		exit(1);
	}

	if(send(clientSock,temp,strlen(temp),0)==SOCKET_ERROR)
	{
		puts("CLIENT:	send() error.");
		closesocket(clientSock);
		exit(1);		
	}
	
	puts("CLIENT: Sending Complete.");
	printf("CLIENT:	Send %s\n",temp);
	memset(in_buf,'\0',BUFLEN);
	if((msgLen=recv(clientSock,in_buf,BUFLEN,0)) >0 ){
        in_buf[msgLen]='\0';        
	}   
	for(i=0;i<strlen(in_buf);i++){	
       if(in_buf[i]==1)      sign=0;
       else if(in_buf[i]==2) sign=1;
       num=in_buf[++i];
       if(sign==0){
           for(j=0,p_total=0;j<num;j++,i++)     
                  p_total+=(unsigned char)in_buf[i+1]*(long)pow(16.0,2*(num-j)-2);
           sprintf(string,"%lu",p_total);
       }
       else if(sign==1){
           for(j=0,n_total=0;j<num;j++,i++)
			    n_total+=(unsigned char)in_buf[i+1]*(long)pow(16.0,2*(num-j)-2);
           sprintf(string,"%ld",n_total);
       }
	   printf("CLIENT:	Sending %s \n",string);
	   if(send(clientSock,string,strlen(string),0)==SOCKET_ERROR)
	   {
			puts("CLIENT:	send() error.");
			closesocket(clientSock);
			exit(1);		
	   }
    system("PAUSE");
	}

	memset(in_buf,'\0',sizeof(in_buf));
	if(msgLen <0){
		puts("CLIENT:	recv() error.");
		closesocket(clientSock);
		exit(1);
	}
	
	if((msgLen=recv(clientSock,in_buf,BUFLEN,0)) >0 ){
        in_buf[msgLen]='\0';        
	}
	if(in_buf[0]!='#'){
		puts("SERVER:	encoding error.");
		system("PAUSE");
		exit(1);
	}
	memset(in_buf,'\0',sizeof(in_buf));
	fin=fopen("sock.c","r");
	while((fgets(in_buf,100,fin))!=NULL){
		if(send(clientSock,in_buf,strlen(in_buf),0)==SOCKET_ERROR)	
		{
			puts("CLIENT:	send() error.");
			closesocket(clientSock);
			exit(1);
		}
		memset(in_buf,'\0',sizeof(in_buf));
	}
	fclose(fin);
	puts("CLIENT: Send Source Code Complete.");
	puts("CLIENT: Close the socket.");
	closesocket(clientSock);

    WSACleanup();
    system("PAUSE");

    return 0;    
}
    
