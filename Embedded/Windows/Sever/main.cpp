#include <cstdlib>
#include <iostream>

using namespace std;
#include <windows.h>

#define BUFLEN 512

void errormesg(int sock,char *buff1)
{
    printf("SERVER: %s error.",buff1);
    closesocket(sock);
    system("PAUSE");
    exit(1);
}
int namesock(int serverSock)
{
    struct sockaddr_in serverAddr;    
    memset((char *)&serverAddr,0, sizeof(struct sockaddr_in));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    serverAddr.sin_port=0;  
          
    if(bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr_in)))
        errormesg(serverSock,"bind()");
        
    return serverSock;
}
void getmesg(int sock)
{
    int len_addr=sizeof(struct sockaddr_in);
    char hostname[50];
    struct hostent *hp;
    struct sockaddr_in ip;
    
    if(gethostname(hostname, 50)==0){
        if((hp = gethostbyname(hostname))){
            memcpy(&ip.sin_addr,hp->h_addr,hp->h_length);
            printf("SERVER: Local IP Address: %s\n",inet_ntoa(ip.sin_addr));
        }    
    }   
    if(getsockname(sock,(struct sockaddr *)&ip,&len_addr)){
        puts("SERVER: getsockbyname() error");
    }    
    printf("SERVER: Local Port Number is %d\n",ntohs(ip.sin_port));
}

int main(int argc, char *argv[])
{
    int serverSock,clientSock, clientLen,msgLen;
    struct sockaddr_in  clientAddr;
    char in_buf[BUFLEN];
    WSADATA wsaData;
    WSAStartup(MAKEWORD(1,1),&wsaData);
/*********************Open Socket**********************************************/    
    if((serverSock=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        errormesg(serverSock,"TCP socket()");
/*********************Name Socket**********************************************/         
    serverSock=namesock(serverSock);
    getmesg(serverSock);
/*********************Listen***************************************************/    
	if(listen(serverSock, 1))
        errormesg(serverSock,"listen()");    
/***************************Accept*********************************************/
    clientLen=sizeof(struct sockaddr_in);       	
	if((clientSock=accept(serverSock, (struct sockaddr *)&clientAddr, &clientLen)) < 0)
        errormesg(serverSock,"accept()");

	printf("SERVER: Client IP Address is %s\n", inet_ntoa(clientAddr.sin_addr));  
	printf("SERVER: Client Port Number is %d\n", ntohs(clientAddr.sin_port));
/***************************Recv*********************************************/    
    do{
        msgLen=recv(clientSock, in_buf, BUFLEN, 0);
        if(msgLen>0){
            in_buf[msgLen]='\0';
            cout<<"SERVER: Recving "<<in_buf<<endl;            
        }
        else if(msgLen<0){
            closesocket(clientSock);
            cout<<"SERVER: Close client socket.\n";
        }
            
    }while(msgLen>=0);
    
    closesocket(clientSock);        
    closesocket(serverSock);     
       
    WSACleanup();  
    system("PAUSE");
    return EXIT_SUCCESS;
}
