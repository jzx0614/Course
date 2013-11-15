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
#include "register.h"
#include "modeTable.h"

int main()
{
    char over;
    do{
        ModeTable ATable;
        char command[10],m[7];
        char mcode_2[9],hex[3];
    
        cout<<"Input: ";
        cin>>command;
        for(int i=0;i<strlen(command);i++) command[i]=toupper(command[i]);

        int format=ATable.search(command);//讀進指令 回傳Format

        switch(format){
                case 0: 
                   cout<<"This isn't command.";
                   break;
                case 1:                    //Format 1
                   strcpy(mcode_2,ATable.getopcode());
                   cout<<"\nMachine code(base2) :";
                   for(int i=0;i<8;i++)
                   {
                      if(i%4==0) cout<<" ";
                      cout<<mcode_2[i];
                   } 
                   break; 
                case 2:                   //Format 2
                   cin >>m;
                   for(int i=0;i<strlen(m);i++) m[i]=toupper(m[i]);
                   ATable.indication_2(m);               
                   break;
                case 3:                   //Format 3
                   cin>>m;
                   ATable.indication(m); 
                   ATable.show();
                   break;
                case 4: 
                   cin>>m;
                   ATable.indication_4(m); 
                   break;                                    
        }

        cout <<"\n\n(0)contiuns (1)exit: ";
        cin>>over;
        cout << endl;
        
    }while(over=='0');
    system("PAUSE");
}
