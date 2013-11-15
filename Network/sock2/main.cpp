#include <iostream>
#include <stdlib.h>

using namespace std;
#include <windows.h>
#include <winsock.h>
#define BUFLEN 512

void errormesg(int,char *);
int namesock(int);
void getmesg(int,char *);
void tcp_sendmesg(int,char *);
int tcp_recvmesg(int,char *);
int udp_mesg(int,char *,int);
int main(int argc, char *argv[])
{
    int t_serverSock,u_serverSock,byte;
    int clientSock, clientLen,msgLen;
    struct sockaddr_in  clientAddr;
    char in_buf[BUFLEN],ans[BUFLEN];
    
    WSADATA wsaData;
    WSAStartup(MAKEWORD(1,1),&wsaData);

/*********************Open Socket**********************************************/
    if((t_serverSock=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        errormesg(t_serverSock,"TCP socket()");
    
    if((u_serverSock=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        errormesg(u_serverSock,"UDP socket()");
/*********************Name Socket**********************************************/   
    t_serverSock=namesock(t_serverSock);
    u_serverSock=namesock(u_serverSock);

    getmesg(t_serverSock,"TCP");
    getmesg(u_serverSock,"UDP");
/*********************Listen***************************************************/
	if(listen(t_serverSock, 1))
        errormesg(t_serverSock,"listen()");
/***************************Accept*********************************************/
    clientLen=sizeof(struct sockaddr_in);       	
	if((clientSock=accept(t_serverSock, (struct sockaddr *)&clientAddr, &clientLen)) < 0)
        errormesg(t_serverSock,"accept()");

	printf("SERVER: Client Port Number is %d\n", ntohs(clientAddr.sin_port));
	printf("SERVER: Client IP Address is %s\n", inet_ntoa(clientAddr.sin_addr));    
/******************************************************************************/
    
    cout<<"\nSERVER: sending C09102014.\n";
    tcp_sendmesg(clientSock,"C09102014");
        
    tcp_recvmesg(clientSock,in_buf);
        
    cout<<"SERVER: sending ";
    for(int i=0;i<strlen(in_buf);i++)
        printf("0x%X ",in_buf[i]);
    cout<<endl;
     
    tcp_sendmesg(clientSock,in_buf);
        
    
    memset(ans,0,BUFLEN);
    do{
        byte=udp_mesg(u_serverSock,in_buf,clientSock);        
        ans[0]+=1;ans[ans[0]]=byte;
    }while(in_buf[0]!='*');    
    ans[ans[0]]='\0';ans[0]-=1;

    cout<<"\nSERVER: sending ";
    for(int i=0;i<strlen(ans);i++)
       if(ans[i]<0)
                printf("%d ",ans[i]+256);
        else
                printf("%d ",ans[i]);
    cout<<endl;    

    tcp_sendmesg(clientSock,ans);

    recv(clientSock, in_buf, BUFLEN, 0);    
    cout<<"SERVER: Answer is "<<in_buf<<endl;       
/***************************end*********************************************/    
    closesocket(t_serverSock);
    closesocket(u_serverSock);  
    closesocket(clientSock);
    system("PAUSE");
    WSACleanup();
    	
    return 0;
}
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
void getmesg(int sock,char *type)
{
    struct sockaddr_in serverAddr;
    int serverLen;
    serverLen=sizeof(struct sockaddr_in);
    
    if(getsockname(sock, (struct sockaddr *)&serverAddr, &serverLen))
        errormesg(sock,"getsockname()");	    

	printf("SERVER: %s Local IP Address is %s\n",type,inet_ntoa(serverAddr.sin_addr));
	printf("SERVER: %s Local Port Number is %d\n",type,ntohs(serverAddr.sin_port));
}
void tcp_sendmesg(int sock,char *out_buf)
{
    if(send(sock, out_buf, strlen(out_buf), 0) < 0)	{
   		closesocket(sock);
	    errormesg(sock,"TCP send()");
    }    
}
int tcp_recvmesg(int clientSock,char *in_buf)
{
    fd_set readfds;
    struct timeval timeout;
    int nRet,nfds,msgLen,byte=0;
    
    FD_ZERO(&readfds);
    FD_SET(clientSock,&readfds);
    timeout.tv_sec=6;
    timeout.tv_usec=0;
    memset(in_buf,0,BUFLEN);
    cout<<"SERVER: TCP byte recv: ";
    do{
        msgLen=0;
        nRet=select(nfds,&readfds,NULL,NULL,&timeout);
        if(nRet>0){	
            msgLen=recv(clientSock, in_buf, BUFLEN, 0);
    	    byte+=msgLen;
    	    printf("%3d ",msgLen);
       	} 
        else if(nRet<0)
            errormesg(clientSock,"TCP recv()");        
    }while((nRet!=0)||(msgLen!=0));
    cout<<endl;
    return byte;
}
int udp_mesg(int sock,char* in_buf,int clientSock)
{
    int msgLen,clientLen=sizeof(struct sockaddr_in);
    struct sockaddr_in clientAddr;
    memset(in_buf,0,BUFLEN);
    
    fd_set readfds,writefds;
    struct timeval timeout;
    int nRet,nfds,byte;
    
    FD_ZERO(&readfds);    
    FD_SET(sock,&readfds);

    timeout.tv_sec=3;
    timeout.tv_usec=0;
    
	memset((char *)&clientAddr,0, sizeof(struct sockaddr_in));
    
    do{
        byte=0;
        FD_ZERO(&readfds);                
        FD_SET(sock,&readfds);
        nRet=select(nfds,&readfds,NULL,NULL,&timeout);   
        if(nRet>0){
        	if((msgLen=recvfrom(sock, in_buf, BUFLEN, 0, (struct sockaddr *)&clientAddr, &clientLen)) < 0)
        	    errormesg(sock,"recvfrom()");
     	    cout<<"\nSERVER: UDP recv "<<in_buf;
	            
        } 
        else if(nRet==0){
            if(msgLen!=0){
                cout<<" then sending "<<in_buf<<endl;
                if (in_buf[0]=='@')cout<<"SERVER: starting ...\n";
                if(sendto(sock, in_buf, strlen(in_buf), 0, (struct sockaddr *)&clientAddr, sizeof(struct sockaddr_in)) < 0)
                    errormesg(sock,"sentfrom()");
                byte=tcp_recvmesg(clientSock,in_buf);        
                printf("SERVER: recving %3d byte ",byte);
            }                                       
     	} 
 	}while(byte==0);
 	return 	byte;
}

