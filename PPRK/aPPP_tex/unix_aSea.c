#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<unistd.h>

#include<arpa/inet.h>
#include<pthread.h>

#include <aPPRK.h>
#include <myPPRK.h>

#include <stdlib.h>

#define BUFLEN 512
#define DEBUG	1
void errormesg(int,char *);
void getmesg(int,char *);
int connectsock(int);

int clientSock;
int cm[3];


//wangfj
int maze[15][5];
int counter=-1;
int TH = 200;
int mov_state=0;
int bk_stat=0;


void socket_Init();

int recvmesg(char *);
void sendmesg(char *);

void socket_End();

int Out_maze();
void Find_Cross();
void Action();
void Exit_Cross();
int main(int argc, char *argv[]){
  char recv_buf[BUFLEN];
  char temp[10];
  int Test;
  //Jzx's Code
  
  //---------------------------------------------------
  //0.init PPRK and Socket


//	printf("TH?");
//	scanf("%d",&TH);

	
	myPPRK_Init();

  //     printf("TH?");
   //     scanf("%d",&TH);

//	myPPRK_Move();

	socket_Init();
// 	myPPRK_Move();

	printf("TH?");
      	scanf("%d",&TH);

	myPPRK_Move();



//	memset(maze,0,sizeof(maze));
/*  do{
  //wangfj's Code
  //1. GO
	myPPRK_Move();
  //---------------------------------------------------
  //2.Find_Cross
	Find_Cross();
	printf("Find_Cross\n");
	
  //---------------------------------------------------
  //3.Where will go ?
	Action();
	printf("Action\n");


  //---------------------------------------------------
  //3.Exit_Cross
	Exit_Cross();
	printf("Exit_Cross\n");
*/
  //Jzx's Code
  //---------------------------------------------------
  //1.Recv_Help_msg
  do{
	if(recvmesg(recv_buf)!=0){
    		printf("CLIENT: TCP recv: %s\n",recv_buf);
	}
  }while(strcmp(recv_buf,"Help Me")!=0);


  //---------------------------------------------------
  //2.Stop and Wait Car1
	myPPRK_Stop(2000);
  //---------------------------------------------------
  //3.Car1 ready ok.
  printf("CLIENT: TCP recv: ");
  do{
        if(recvmesg(recv_buf)!=0){
                printf("%s\n",recv_buf);
        }
  }while(strcmp(recv_buf,"OK.Let's go!")!=0);
        	
  //---------------------------------------------------
  //4.Turn back 180
	myPPRK_Turn(0);
  //---------------------------------------------------
  //5.Ready Go and Send message to Car1
	sendmesg("I turn 180 finish.");
//	while(1){
		myPPRK_Move();
//	}
  

 //wangfj's Code
  while(1){

		 myPPRK_Move();
		Find_Cross();
//		printf("find cross\n");
//		sendmesg("Intersection");
//		printf("send intersection msg\n");

		
//		myPPRK_Move();
		aMM(2500);
//		if(Out_maze()==1)break;
		Exit_Cross();
		
  }

  //Send turn right and left	
   	socket_End();

   return 0;
}
void errormesg(int sock,char *buff1)
{
    printf("CLIENT: %s error.",buff1);
    close(sock);
    exit(1);
}
int connectsock(int client)
{
    struct sockaddr_in serverAddr;    
    memset((char *)&serverAddr,0, sizeof(struct sockaddr_in));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_addr.s_addr=inet_addr("192.168.1.115");
    serverAddr.sin_port=htons(30000);  
    if(connect(clientSock,(struct sockaddr *)&serverAddr,sizeof(struct sockaddr_in))<0)  
        errormesg(client,"connect()");
        
    return client;
}
void getmesg(int sock,char *type)
{
    struct sockaddr_in serverAddr;
    int serverLen;
    serverLen=sizeof(struct sockaddr_in);
    
    if(getsockname(sock, (struct sockaddr *)&serverAddr, &serverLen))
        errormesg(sock,"getsockname()");	    

	printf("CLIENT: %s Client IP Address is %s\n",type,inet_ntoa(serverAddr.sin_addr));
	printf("CLIENT: %s Client Port Number is %d\n",type,ntohs(serverAddr.sin_port));
}
void socket_Init(){
    struct sockaddr_in s_address;
    if((clientSock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))<0){
	errormesg(clientSock,"TCP socket()");
    }

    printf("CLIENT: Connect Start\n");
    clientSock=connectsock(clientSock);
    getmesg(clientSock,"TCP");
    
}
void socket_End(){
    close(clientSock);
}
void sendmesg(char *out_buf)
{
    if(send(clientSock, out_buf, strlen(out_buf), 0) < 0){
    	errormesg(clientSock,"TCP send()");
    }    
    printf("CLIENT: TCP Send: %s\n",out_buf);
}
int recvmesg(char *in_buf)
{
    fd_set readfds;
    struct timeval timeout;
    int nRet,msgLen,byte=0;
    int nfds =  clientSock+1;

    FD_ZERO(&readfds);
    FD_SET(clientSock,&readfds);
    timeout.tv_sec=0;
    timeout.tv_usec=300;

    memset(in_buf,0,BUFLEN);
    do{
        msgLen=0;
        nRet=select(nfds,&readfds,NULL,NULL,&timeout);
        if(nRet>0){	
            msgLen=recv(clientSock, in_buf, BUFLEN, 0);
    	    byte+=msgLen;
       	} 
        else if(nRet<0)
            errormesg(clientSock,"TCP recv()");        
    }while((nRet!=0)||(msgLen!=0));
    return byte;
}


void Find_Cross(){
    do{
	myPPRK_Sensor(cm);
	printf("iv1=%d\n",cm[1]);

    }while(cm[1] > TH );	
//    printf("iv0=%d iv1=%d iv2=%d\n",cm[0],cm[1],cm[2]);
    myPPRK_Stop(20);

	printf("find cross\n");
                sendmesg("Intersection");
                printf("send intersection msg\n");



    myPPRK_Turn(1);


}
void Action(){
    int i,j,direct;    
 
    myPPRK_Stop(2000);
    
   /*
    //push start
    printf("PUSH Start\n");
    maze[++counter][1]=1;
    maze[counter][3]= (cm[0]<250) ? 1: 0;
    maze[counter][2]= (cm[1]<TH)  ? 1: 0;
    maze[counter][4]= (cm[2]<TH)  ? 1: 0;

    
    for(i=2;i<5;i++){
	if(maze[counter][i]){
		maze[counter][0]=i-1;
		break;
	}
    }
    for(i=0;i<5;i++)
	printf("%d \t",maze[counter][i]);
    printf("\n");
    //push end	

    if(maze[counter][0]!=2)
    	myPPRK_Turn(maze[counter][0]);	
    myPPRK_Move();
   
 
    while(maze[counter][0]==0){
	printf("POP Start\n");
    //pop
	for(i=0;i<5;i++){maze[counter][i]=0;}
        counter--;		
    //pop end

    //RE-Search path
	direct=maze[counter][0];
	maze[counter][direct+1]=0;
	for(i=2;i<5;i++){
        	if(maze[counter][i]){
                	maze[counter][0]=i-1;
        	}
    	}
	
	Find_Cross();
	myPPRK_Turn((maze[counter][0]-direct)%4);
	
    } 
 */   
		
	if(bk_stat==1){
		printf("bk_stat=1\n");
		if(cm[1]<TH){ 
			if(maze[counter-1][0]==2){
				maze[counter-1][0]=3;
			}
			else if(maze[counter-1][0]==1){
				maze[counter-1][0]=2;
			}
			maze[counter][0]=3; //left
			myPPRK_Turn(3);
			counter++;
			mov_state=1;	
					
			printf("bk_stat=0\n");
			bk_stat=0;
		}
		else{ 
			counter--;
			for(i=0;i<5;i++)maze[counter][i]=0;
			mov_state=1;	
		}
	}
	else if(mov_state==0){
		printf("mov_stat=0\n");
		myPPRK_Stop(1);
		if(cm[1]<TH){

			maze[counter][0]=1; //right
			counter++;
			myPPRK_Turn(1);
			mov_state=1;
		}else{			
			if(cm[0]<360){ 
				maze[counter][0]=2; 
				counter++;		
				mov_state=1;
		 	}
			else if(cm[0]>360){ 
				if(cm[2] > TH){//dead end
					bk_stat=1;
					mov_state=1;
					myPPRK_Turn(0);		
					printf("\n\ndead end: %d  ",counter);	
					for(j=0;j<counter;j++) printf("%d ",maze[j][0]);
						printf("\n\n");
				}
				else{
					maze[counter][0]=3; //left
					myPPRK_Turn(3);
					counter++;						
				}
			}
		}
		
	}
	else if(mov_state==1){ //in cross go on
				//do nothing		
		printf("crossing\n");	
	}
	
	myPPRK_Move();

	
}
void Exit_Cross(){
    int s[2];
	int i,j;
    //store sensor state
/*    myPPRK_Sensor(cm);
    s[0] = (cm[1]< TH ) ? 0 : 1;
    s[1] = (cm[2]< TH ) ? 0 : 1;
    
    printf("Exit_Cross Loop\n");
    while(1){
        myPPRK_Sensor(cm);
	if(s[0]==0 && cm[1] >TH){ break;}
	if(s[1]==0 && cm[2] >TH){ break;}
    }
    myPPRK_Stop(2000);
    myPPRK_Move();
    printf("Exit_Cross End\n");
 */

	printf("line\n");

  while(1){
	myPPRK_Sensor(cm);

	 printf("iv0=%d iv1=%d iv2=%d\n",cm[0],cm[1],cm[2]);

	if(cm[1] > TH && cm[2] > TH )break;
  }
	printf("line end\n");


/*
	printf("line\n");   
    while(1){
  
	    myPPRK_Sensor(cm);
      
	    if(cm[1]>TH && cm[2]>TH ){
//		    printf("line\n");
		    if(mov_state==1){
	        	printf("netx section:\n");
			for(j=0;j<counter;j++){
				printf("counter %d =%d\n",j,maze[j][0]);
			}				
			mov_state=0;
		    }
	    	    if(mov_state==88)mov_state=99;			
	            myPPRK_Move();

		    break;

	    }

   }
  */
}
int Out_maze(){

	int ha=0;
	printf("move on?");
	scanf("%d\n",&ha);
	return ha;
/*
		if(counter<0)return 1;
			
		
		if(maze[counter][0] ==1){//back is left
			myPPRK_Turn(3);	
		    	myPPRK_Move();
			
		
			counter--;	
		}else if(maze[counter][0] ==2){ //up
			//myPPRK_Turn(3);	
		    	myPPRK_Move();
			
			counter--;
		}else if(maze[counter][0] ==3){
			myPPRK_Turn(1);	
		    	myPPRK_Move();

			counter--;
		}else if(maze[counter][0] ==4){
			printf("maze[%d][0] ==4\n",counter);
			
			counter--;
		}else{
			printf("out_Maze error: %d\n",maze[counter][0]);
		
		
		}		

		return 0;
*/
}
