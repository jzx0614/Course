#include <stdio.h>
#include "myPPRK.h"
#include <unistd.h>

#define IR0 0
#define IR1 1
#define IR2 2

aIOLib ioRef = NULL;
aPPRKLib pprkRef = NULL;
aStemLib stemRef = NULL;
aStreamRef  linkStream =NULL;
int W[3]={140,140,140};
int interval=5500;

double RawToCM(int raw_data){
        double signal[16]={538,455.9,385.8,341.8,297.2,268.9,237.3,217.8,197.2,168.3,143.7,121.3,105.8,93.1,74.2,49.1};
        double distance[16]={10,12.5, 15.0, 17.5, 20.0, 22.5, 25.0, 27.5, 30.0, 35.0, 40.0, 45.0, 50.0,55.0,60.0,75.0};
        double ans;
        int i;
        for(i=1;i<15;i++){
                if(raw_data>=signal[i]){break;}
        }
        if(i==15) i=14;
        ans=(raw_data-signal[i])/(signal[i-1]-signal[i])*(distance[i-1]-distance[i])+distance[i];
        return ans;
}


void aMM(int tt){

	aServo_SetPositionAbs(stemRef, 2, 0,  W[0]);
        aServo_SetPositionAbs(stemRef, 2, 1,  W[1]+100);
        aServo_SetPositionAbs(stemRef, 2, 2, W[2]-100);

	aIO_MSSleep(ioRef,tt,NULL);




}

void myPPRK_Move(){
	aServo_SetPositionAbs(stemRef, 2, 0, W[0]);
        aServo_SetPositionAbs(stemRef, 2, 1, W[1]+100);
        aServo_SetPositionAbs(stemRef, 2, 2, W[2]-100);
}
void myPPRK_Test(){
	int moving_interval;
        do{
                printf("Input a interval:");
                scanf("%d",&moving_interval);
                aServo_SetPositionAbs(stemRef, 2, 0, W[0]+100);
                aServo_SetPositionAbs(stemRef, 2, 1, W[1]+100);
                aServo_SetPositionAbs(stemRef, 2, 2, W[2]+100);
                aIO_MSSleep(ioRef,moving_interval,NULL);
                myPPRK_Stop();
		if(moving_interval!=0){interval=moving_interval;}
        }while(moving_interval!=0);
}

void myPPRK_Turn(int direct){
	int spin_time,speed;
	if(direct == 1 || direct ==3){
		spin_time=interval/4;
	}
	else if(direct ==0){
		spin_time=interval/2;
	}
	speed = (direct < 2) ? 100 : -100 ;
	aServo_SetPositionAbs(stemRef, 2, 0, W[0]+speed);
	aServo_SetPositionAbs(stemRef, 2, 1, W[1]+speed);
        aServo_SetPositionAbs(stemRef, 2, 2, W[2]+speed);
	aIO_MSSleep(ioRef,spin_time,NULL);
	myPPRK_Stop();
}

void myPPRK_Stop(){
        aServo_SetPositionAbs(stemRef, 2, 0, W[0]);
        aServo_SetPositionAbs(stemRef, 2, 1, W[1]);
        aServo_SetPositionAbs(stemRef, 2, 2, W[2]);
}

void myPPRK_Init()
{
  aErr pprkErr = aErrNone;
  aErr ioErr = aErrNone; 
  aErr stemErr = aErrNone;
  aErr streamErr = aErrNone;
  int init_wheel;
  int value0,value1,value2;
  /* Get the references to the aIO and aStem library objects. */
  if (aIO_GetLibRef(&ioRef, &ioErr))
  {
    printf("IO ERR = %d",(int)ioErr);
    return;
  }

  if (aPPRK_GetLibRef(&pprkRef, &pprkErr))
  {
    printf("pprk ERR = %d",(int)ioErr);
    return;
  }

  if (aStem_GetLibRef(&stemRef, &stemErr))
  {
    printf("stem ERR = %d",(int)stemErr);
    return;
  }

  #define aPORTNAME "ttyS0"
  #define aPORTSPEED 9600

  aStream_CreateSerial(ioRef, aPORTNAME, aPORTSPEED, &linkStream, &streamErr);
  if(streamErr != aErrNone)
  {
    printf("stream ERR = %d\n", (int)streamErr);
    return;
  }
  aStem_SetStream(stemRef, linkStream, kStemModuleStream, &pprkErr);
  if(streamErr != aErrNone)
  {
    printf("stream ERR = %d\n", (int)streamErr);
    return;
  }
  printf("Do you set wheel (1/0) ? ");
  scanf("%d",&init_wheel);
  if(init_wheel){
	printf("Input 3 wheel stop speed: ");
  	scanf("%d %d %d",&W[0],&W[1],&W[2]);
  }
  printf("Do you set spin_interval (1/0) ? ");
  scanf("%d",&init_wheel);
  if(init_wheel){
	myPPRK_Test();	
  }
  myPPRK_Stop();

  do{
  aAnalog_ReadInt(stemRef, 2, 0, &value0);
  aAnalog_ReadInt(stemRef, 2, 1, &value1);
  aAnalog_ReadInt(stemRef, 2, 2, &value2);
  printf ("Start (%d,%d,%d)\n",value0,value1,value2);
  }while(value0==0 || value1 ==0 || value2==0);
}

void Find_Car(){
	int value0,value1,value2;
	double distance0,distance1,distance2;
	int IS_Car=0;
	printf("SERVER:	FIND_CAR Start\n");
	do{
		do{
        		aAnalog_ReadInt(stemRef, 2, 0, &value0);
			distance0 = RawToCM(value0);
		}while(value0==0);

		if(distance0 <30 ){
			printf ("Find Car %d\n",value0);
			IS_Car = 1;
		}
	}while(!IS_Car);
	printf("SERVER:	FIND_CAR End\n");
}
void follow_Car0(){
	int IS_OK=0,value0;
	double distance0;
	printf("SERVER: followCar0 Start\n");
	myPPRK_Move();
	do{
	        do{
		    aAnalog_ReadInt(stemRef, 2, 0, &value0);
               	    distance0 = RawToCM(value0);		
		}while(value0==0);
		if(distance0 >=10 && distance0 <=15){
			printf("Follow Mode ok\n");
			IS_OK=1;
		}
	}while(!IS_OK);
	myPPRK_Stop();
}
void myPPRK_Sensor(int *value){
	do{
  		aAnalog_ReadInt(stemRef, 2, 0, &value[0]);
  		aAnalog_ReadInt(stemRef, 2, 1, &value[1]);
  		aAnalog_ReadInt(stemRef, 2, 2, &value[2]);
	}while(value[0]==0 || value[1] ==0 || value[2]==0);
}
