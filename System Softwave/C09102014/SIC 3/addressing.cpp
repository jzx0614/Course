#include <cstring>
#include <iostream>
using namespace std;

#include "addressing.h" // class's header file


void Addressing::set(char *buff1,int buff2,char *buff3)
{   
    strcpy(Mnem,buff1);
    Format=buff2;
    strcpy(Opcode,buff3);
}
void Addressing::show()
{
        cout <<"\nFormat: "<<Format<<"\nOpcode: "<<Opcode<<endl;
}





