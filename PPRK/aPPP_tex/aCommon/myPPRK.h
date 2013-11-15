#include "aIO.h"
#include "aPPRK.h"
#include "aServo.h"
#include "aAssert.h"

#include "aStem.h"      /* stem library header     */
#include "aAnalog.h"    /* A2D input routines      */
#include "aDigital.h"   /* digital IO routines     */


double RawToCM(int raw_data);

void myPPRK_Move();
void myPPRK_Stop();
void myPPRK_Init();

void aMM(int);
void Find_Car();
void follow_Car0();
void myPPRK_Turn(int);
void myPPRK_Test();
void myPPRK_Sensor(int*);
