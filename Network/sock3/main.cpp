#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <winsock.h>

#define BUFLEN 256

class chatroom{
    public:
        chatroom();
        void initsock();
        void working();        
    private:
        int searchempty();
        void acceptconnect();        
        void sendmesg(char *,int);
        void recvmesg(int);
        void closeconnect(int);
                
        struct sockaddr_in s_address,c_address[10];
        int s_sock,c_sock[10],len_addr,online;
        bool c_alive[10];
  
};

chatroom::chatroom()
{   
    memset(c_alive,0,10);
    memset(c_address,0,10);
    len_addr=sizeof(struct sockaddr_in);
    online=0;
}
void chatroom::initsock()
{
    if((s_sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))<0){
        puts("Server *: socket() error");
        exit(1);
    }
    
    memset((struct sockaddr_in *)&s_address,0,sizeof(s_address));
    s_address.sin_family=AF_INET;
    s_address.sin_port=0;
    s_address.sin_addr.s_addr=htonl(INADDR_ANY);
    
    if(bind(s_sock,(struct sockaddr *)&s_address,sizeof(s_address))){
        puts("Server *: bind() error");
        closesocket(s_sock);
        exit(1);   
    }         

    
    char hostname[50];
    struct hostent *hp;
    struct sockaddr_in ip;
    
    if(gethostname(hostname, 50)==0){
        printf("Server *: Server hostname: %s\n",hostname);
        if((hp = gethostbyname(hostname))){
            memcpy(&ip.sin_addr,hp->h_addr,hp->h_length);
            printf("Server *: Local IP Address: %s\n",inet_ntoa(ip.sin_addr));
        }    
    }   
    if(getsockname(s_sock,(struct sockaddr *)&ip,&len_addr)){
        puts("SERVER *: getsockbyname() error");
    }    
    printf("SERVER *: Local Port Number is %d\n",ntohs(ip.sin_port));
        
    if(listen(s_sock,10)){
        puts("Server *: listen() error");
        closesocket(s_sock);
        exit(1);        
    }      
}
void chatroom::working()
{
    fd_set readfds;
    int nRet;
    struct timeval timeout;
    timeout.tv_sec=1;
    timeout.tv_usec=0;
  
    while(1){
        FD_ZERO(&readfds);    
        FD_SET(s_sock,&readfds);
        for(int i=0;i<10;i++)
            if(c_alive[i]) FD_SET(c_sock[i],&readfds);
            
        nRet=select(0,&readfds,NULL,NULL,&timeout);
        if(nRet>0){
            if(FD_ISSET(s_sock,&readfds))
                acceptconnect();
            for(int i=0;i<10;i++)
                if(c_alive[i]&&(FD_ISSET(c_sock[i],&readfds)))
                    recvmesg(i);
        }    
    }    
}
int chatroom::searchempty()
{
    for(int i=0;i<10;i++)
        if(!c_alive[i])
            return i;        
}
void chatroom::acceptconnect()
{
    int p=searchempty();
    memset((struct sockaddr_in *)&c_address[p],0,sizeof(c_address[p]));
    if((c_sock[p]=accept(s_sock,(struct sockaddr *)&c_address[p],&len_addr))<0)
        puts("SERVER *: accept() error.");
    else{
        c_alive[p]=true;
        if(send(c_sock[p],"C09102014",9, 0) < 0){
            c_alive[p]=false;
            closesocket(c_sock[p]);
            return;
        }
    char in_buf[BUFLEN];
    int msgLen,test;
    if(( msgLen=recv(c_sock[p],in_buf,BUFLEN,0)) >0 ){
        in_buf[msgLen]='\0';}
           
       char out_buf[BUFLEN];
        
        sprintf(out_buf,"SERVER *: Client at %s(%d) connecting...\n",
               inet_ntoa(c_address[p].sin_addr),ntohs(c_address[p].sin_port));
        printf("%s",out_buf);
        printf("SERVER *: %d client(s) connecting...\n",++online);
        sendmesg(out_buf,p); 
    }    
}
void chatroom::sendmesg(char out[],int nosend)
{
    for(int i=0;i<10;i++)
        if(c_alive[i]&&i!=nosend)
            if(send(c_sock[i], out, strlen(out), 0) < 0)	
        	    printf("SERVER *: TCP send() clinet %d error\n" ,i);  
}
void chatroom::recvmesg(int p)
{
    char in_buf[BUFLEN];
    int msgLen;
    if(( msgLen=recv(c_sock[p],in_buf,BUFLEN,0)) >0 ){
        in_buf[msgLen]='\0';
        printf("SERVER *: %s",in_buf);
        sendmesg(in_buf,p);
    }
   	else if(msgLen ==0)
        closeconnect(p);
    else if(msgLen <0)
        closeconnect(p);    
}
void chatroom::closeconnect(int p)
{
    char out_buf[BUFLEN];
    sprintf(out_buf,"SERVER *: Client at %s(%d) leaving...\n",
            inet_ntoa(c_address[p].sin_addr),ntohs(c_address[p].sin_port));    
    c_alive[p]=false;
    printf("%s",out_buf);
    printf("SERVER *: %d client(s) connecting...\n",--online);
    sendmesg(out_buf,p);
    closesocket(c_sock[p]);
}
int main()
{
  WSADATA wsaData;
  WSAStartup(MAKEWORD(1,1),&wsaData);
  class chatroom sock3;
  sock3.initsock();
  sock3.working();

  system("PAUSE");	
  return 0;
}
