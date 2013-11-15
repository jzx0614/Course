#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#include <windows.h>

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

int main(int argc, char *argv[])
{
    struct sockaddr_in serverAddr;
    int port,clientSock;
    char ip[16],out_buf[100];
        
    WSADATA wsaData;
    WSAStartup(MAKEWORD(1,1),&wsaData);
/*
    cout << "Input IP Address : ";
    cin  >> ip;
    cout << "Input Port Number: ";
    cin  >> port;
*/    
    if((clientSock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))<0){
        puts("CLIENT: socket() error.");
        exit(1);
    }
 
    memset((char *)&serverAddr,'\0',sizeof(struct sockaddr_in));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_addr.s_addr=inet_addr("140.114.78.234");    
    serverAddr.sin_port=htons(30000);
//    serverAddr.sin_addr.s_addr=inet_addr(ip);    
//    serverAddr.sin_port=htons(port);   
    
    if(connect(clientSock,(struct sockaddr *)&serverAddr,sizeof(struct sockaddr_in))<0){
	    puts("CLIENT:	connect() error.");
	    system("PAUSE");
	    closesocket(clientSock);
	    exit(1);
    }
    
    while(1){
       cout<< "Input Send message:";
       cin >> out_buf;
       if(!strcmp(out_buf,"exit")) break;
       sendmsg(clientSock,out_buf);
    };
    for(int i=0;i<20;i++){
         sprintf(out_buf,"This is %2d message.\n",i);
         sendmsg(clientSock,out_buf);
    }     
    system("PAUSE");
    closesocket(clientSock);
    WSACleanup();    
    system("PAUSE");
    return EXIT_SUCCESS;
}
