#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<unistd.h>

#include<arpa/inet.h>

#define BROADCAST "140.114.78.255"
#define UDP_REV_COMMUNICATION_PORT 30000
#define UDP_COMMUNICATION_PORT 30001

void errormesg(int sock,char *buff1){
    printf("SERVER: %s error.\n",buff1);
    close(sock);
    exit(1);
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
int main()
{
	char DevMsg[]={"test broadcast"};
        int sockfd, yes = 1, status, sinlen, buflen;
        struct sockaddr_in sock_in,OtherAddr;
        sinlen = sizeof(struct sockaddr_in);
        memset(&sock_in, 0, sinlen);

	//---------------------------------------
	//Create UDP Socket

	if((sockfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
		errormesg(sockfd,"UDP socket()");
		
	//Broadcast
 	if(setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST,&yes, sizeof(yes))< 0){
		errormesg(sockfd,"Set Brocast Fail.");
	}	
	memset((char *)&sock_in,0, sizeof(struct sockaddr_in));
    	sock_in.sin_family=AF_INET;
    	sock_in.sin_addr.s_addr=htonl(INADDR_ANY);
    	sock_in.sin_port=htons(UDP_REV_COMMUNICATION_PORT);
    
        memset((char *)&OtherAddr,0, sizeof(struct sockaddr_in));
        OtherAddr.sin_family=AF_INET;
        OtherAddr.sin_addr.s_addr=inet_addr(BROADCAST);
        OtherAddr.sin_port=htons(UDP_COMMUNICATION_PORT);

	//Binding
    	if(bind(sockfd, (struct sockaddr *)&sock_in, sizeof(struct sockaddr_in)))
        	errormesg(sockfd,"bind()");
   	getmesg(sockfd,"UDP"); 
    	
	buflen = sizeof(DevMsg);
	while(1){
    	status = sendto(sockfd, &DevMsg, buflen, 0, (struct sockaddr *)&OtherAddr, sinlen);
        if(status == 0)
                printf("broadcasting failed...!!!\n");
        else
                printf("broadcasting........UdpSend finish \n");
	sleep(2);
	}
        shutdown(sockfd, 2);
        close(sockfd);
	return 0;
}

