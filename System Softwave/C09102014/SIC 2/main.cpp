/*
  Name: 簡志軒 
  Class:二資三甲 
  Date: 07/10/04 00:11
  Description: SIC/XE
*/

#include <iostream>
using namespace std;

#include <stdlib.h>
#include<ctype.h>
#include<string.h>

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
        for(int i=0;i<strlen(command);i++) command[i]=toupper(command[i]);

        int format=ATable.search(command);//讀進指令 回傳Format

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
