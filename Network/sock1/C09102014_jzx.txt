#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define BUFLEN 100

void sendmsg(int,char*);
int recvmsg(int,char*);
void decode(int,char*,char*);

int main(int argc,char *argv[])
{
    FILE *fin;
    int clientSock,msgLen,i,j;    
    struct sockaddr_in serverAddr;    
    char in_buf[BUFLEN],string[12];
    char temp[]={"C09102014_jzx.txt"};
   
    int port;
    char ip[16];
    printf("Input IP Address : ");
    scanf("%s",ip);
    printf("Input Port Number: ");
    scanf("%d",&port);
  
    WSADATA wsaData;
    WSAStartup(MAKEWORD(1,1),&wsaData);
           
    if((clientSock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))<0){
        puts("CLIENT: socket() error.");
        exit(1);
    }
    
    memset((char *)&serverAddr,'\0',sizeof(struct sockaddr_in));
    serverAddr.sin_family=AF_INET;
//    serverAddr.sin_addr.s_addr=inet_addr("192.168.0.167");    
//    serverAddr.sin_port=htons(30000);
    serverAddr.sin_addr.s_addr=inet_addr(ip);    
    serverAddr.sin_port=htons(port);

    if(connect(clientSock,(struct sockaddr *)&serverAddr,sizeof(struct sockaddr_in))<0){
	    puts("CLIENT:	connect() error.");
	    system("PAUSE");
	    closesocket(clientSock);
	    exit(1);
    }

    sendmsg(clientSock,temp);          //send filename
    puts("CLINET: Sending number finish."); 
    system("PAUSE");
    
    while(1){
        memset(in_buf,0,sizeof(in_buf));
	    msgLen=recvmsg(clientSock,in_buf);

    	if(in_buf[0]=='#'&& msgLen==1){
            printf("CLIENT: Recving %c\n",in_buf[0]);
    	    puts("CLINET: Encoding finish.");
    	    break;
    	}
      	
	    printf("CLIENT: Recving");	    
	    for(i=0;i<msgLen;i++)
            printf(" 0x%X ",in_buf[i]&0xff);
        printf("\n");

        decode(msgLen,in_buf,string);   
        sendmsg(clientSock,string);          
     } 

    system("PAUSE");    
    memset(in_buf,'\0',sizeof(in_buf));
    fin=fopen("sock.c","r");
    while((fgets(in_buf,100,fin))!=NULL){
        if(send(clientSock,in_buf,strlen(in_buf),0)<0)  
        {
            puts("CLIENT:   send() error.");
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
void sendmsg(int clientSock,char* string){
        if(send(clientSock,string,strlen(string),0)<0)  
        {
            puts("CLIENT:   send() error.");
            closesocket(clientSock);
            system("PAUSE");
            exit(1);
        }
        printf("CLIENT: Sending %s\n",string);
        memset(string,'\0',sizeof(string));
} 
int recvmsg(int clientSock,char* in_buf){
    int msgLen;
    if(( msgLen=recv(clientSock,in_buf,BUFLEN,0)) >0 ){
            in_buf[msgLen]='\0';
            return msgLen;        
    }
     	else if(msgLen ==0){
    	puts("CLIENT: Encoding Error.");
	    system("PAUSE");
	    closesocket(clientSock);
    	exit(1);
    } 
    else if(msgLen <0){
        puts("CLIENT:	recv() error.");
        closesocket(clientSock);
        system("PAUSE");
        exit(1);
    }
}
void decode(int msgLen,char *in_buf,char *string)
{   
    int num,i,j,sign;
    long total;
    
    for(i=0;i<msgLen;){	               
        if(in_buf[i]==1) sign=0;
        else             sign=1;
        
        num=in_buf[++i];
           
        for(j=0,total=0,i=i+1;j<num;j++,i++)     
            if(j==0&&sign==1)
                total+=in_buf[i]<<8*(num-j-1);
            else
                total+=(unsigned char)in_buf[i]<<8*(num-j-1);
           
        if(sign==0)
       		  sprintf(string,"%lu",total);
        else 
       		  sprintf(string,"%ld",total);
    }
    memset(in_buf,0,sizeof(in_buf));
}
