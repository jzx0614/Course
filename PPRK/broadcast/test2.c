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
	char recv_info[15]; 
        int UDPsd;
	int so_reuseaddr=1,yes;
        int somebytes=0;
        struct sockaddr_in MyAddr;
        struct sockaddr_in OthersAddr;
        int sinlen;

	//---------------------------------------------
	//Create UDP Socket
	if((UDPsd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        	errormesg(UDPsd,"UDP socket()");
	
	memset((char *)&MyAddr,0, sizeof(struct sockaddr_in));
    	MyAddr.sin_family=AF_INET;
    	//MyAddr.sin_addr.s_addr=inet_addr(BROADCAST);
    	MyAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    	MyAddr.sin_port=htons(UDP_COMMUNICATION_PORT);
	
	//memset((char *)&OthersAddr,0, sizeof(struct sockaddr_in));
    	//OthersAddr.sin_family=AF_INET;
    	//OthersAddr.sin_addr.s_addr=inet_addr(BROADCAST);
    	//OthersAddr.sin_port=htons(UDP_COMMUNICATION_PORT);
    
	//if(setsockopt(UDPsd, SOL_SOCKET, SO_REUSEADDR,&so_reuseaddr, sizeof(so_reuseaddr))< 0){;
    	// if(setsockopt(UDPsd, SOL_SOCKET, SO_BROADCAST,&yes, sizeof(yes))< 0){
	//	errormesg(UDPsd,"Set Brocast Fail.");
	//}
	if(bind(UDPsd, (struct sockaddr *)&MyAddr, sizeof(struct sockaddr_in)))
    		errormesg(UDPsd,"bind()");
	getmesg(UDPsd,"UDP");
        //receive 
  	while(1){
        	while(somebytes!=sizeof(recv_info))
        	{
           		somebytes+=recvfrom(UDPsd, recv_info, sizeof(recv_info), 0,
					    (struct sockaddr *)&MyAddr, &sinlen);
        	}
        	somebytes=0;
		printf("%s\n",recv_info);
  	}

        shutdown(UDPsd, 2);
        close(UDPsd);

	return 0;
}
