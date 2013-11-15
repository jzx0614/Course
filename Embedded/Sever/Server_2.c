#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define BUFLEN 512

char out_buf[BUFLEN];
pthread_mutex_t mutex;

void errormesg(int sock,char *buff1);
int namesock(int serverSock);
void getlocalmesg(int sock);

void listen_network(int serversock);
void listen_keyboard(void);

int main(int argc, char *argv[])
{
    pthread_t network,keyboard;
    int serverSock;
    
    if((serverSock=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)  // Open a Socket
	errormesg(serverSock,"TCP socket()");

    serverSock=namesock(serverSock);				    // Bind a Socket
    getlocalmesg(serverSock);

    if(listen(serverSock, 1))					    // listen Socket
        errormesg(serverSock,"listen()"); 	

    pthread_mutex_init(&mutex,NULL);
   
    pthread_create(&network,NULL,(void *)&listen_network,(void *)serverSock);
    pthread_create(&keyboard,NULL,(void *)&listen_keyboard,NULL);

    
    while(1){
	if(strlen(out_buf)!=0){
	    pthread_mutex_lock(&mutex);				    // Critical Section start
	    printf("Output: %s\n",out_buf);
	    memset(out_buf,0,sizeof(out_buf));
	    pthread_mutex_unlock(&mutex);			    // Critical Section end
	}
    }

    return 0;
}
void listen_keyboard(void){
    int msgLen,nRet;
    char in_buf[BUFLEN];
    fd_set readfds;
    while(1){
	    msgLen=read(0,in_buf,BUFLEN);
	    in_buf[msgLen]='\0';
	    pthread_mutex_lock(&mutex);
	    strcat(out_buf,in_buf);
	    pthread_mutex_unlock(&mutex);
    }
}
void listen_network(int serverSock){
    int clientSock, clientLen,msgLen,nRet,maxSock;
    struct sockaddr_in  clientAddr;
    struct timeval timeout;
    char in_buf[BUFLEN];

    clientLen=sizeof(struct sockaddr_in);
    while(1){
	if((clientSock=accept(serverSock, (struct sockaddr *)&clientAddr,(socklen_t *)&clientLen)) < 0)
	    errormesg(serverSock,"accept()");
	printf("Network: Client IP Address: %s Port Number: %d\n", inet_ntoa(clientAddr.sin_addr),ntohs(clientAddr.sin_port));
	do {	    // Recv data	
		msgLen=recv(clientSock, in_buf, BUFLEN, 0);
		if(msgLen>0){
		    in_buf[msgLen]='\0';           
		    pthread_mutex_lock(&mutex);                             // Critical Section start		    
		    strcat(out_buf,in_buf);
		    pthread_mutex_unlock(&mutex);                             // Critical Section end
		}
		else{
		    close(clientSock);
		    printf("Network: Client Close socket.\n");
		}
	    
	}while(msgLen>0);
    }    
    close(clientSock);
}
void errormesg(int sock,char *buff1)
{
    printf("Network: %s error.",buff1);
    close(sock);
    exit(1);
}
int namesock(int serverSock)
{
    struct sockaddr_in serverAddr;    
    memset((char *)&serverAddr,0, sizeof(struct sockaddr_in));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    serverAddr.sin_port=htons(30000);  
    if(bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr_in)))
        errormesg(serverSock,"bind()");
        
    return serverSock;
}
void getlocalmesg(int sock)
{
    int len_addr=sizeof(struct sockaddr_in);
    char hostname[50];
    struct hostent *hp;
    struct sockaddr_in ip;
    
   if(gethostname(hostname, 50)==0){
	printf("Network: Local hostname: %s\n",hostname);
        if((hp = gethostbyname(hostname))){
            memcpy(&ip.sin_addr,hp->h_addr,hp->h_length);
            printf("Network: Local IP Address: %s",inet_ntoa(ip.sin_addr));
        }    
    }   

    if(getsockname(sock,(struct sockaddr *)&ip,(socklen_t *)&len_addr)){
        puts("Network: getsockbyname() error");
    }	    
    printf(" Port Number: %d\n",ntohs(ip.sin_port));
}
