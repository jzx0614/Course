/*
  Name: ²�Ӱa 
  Class:�G��T�� 
  Date: 07/10/04 00:11
  Description: SIC/XE
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#include "addressing.h"
#include "modeTable.h"

int main()
{
    char over;
    do{
        ModeTable ATable;
        char command[10],m[7];
        char mcode_2[25],hex[7];
    
        cout<<"Input: ";
        cin>>command;
        int format=ATable.search(command);//Ū�i���O �^��Format

        switch(format){
                case 0: 
                   cout<<"This isn't command.";
                   break;
                case 1:                    //Format 1
                   cout<<endl<<ATable.getopcode()<<endl;//show opcode
                   break;
                   cout<<endl;
                case 2:                   //Format 2
                   cin >>m;
                   cout<<endl<<ATable.getopcode()<<endl;//show opcode                  
                   break;
                case 3:                   //Format 3
                   cin>>m;
                   ATable.indication(m); 
                   ATable.show();
                   break;                                     
        }

        cout <<"\n\n(0)contiuns (1)exit: ";
        cin>>over;
        cout << endl;
        
    }while(over=='0');
    system("PAUSE");
}
