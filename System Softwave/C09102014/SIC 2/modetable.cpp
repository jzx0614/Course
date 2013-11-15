#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#include "addressing.h"
#include "modetable.h" // class's header file
ModeTable::ModeTable()
{  //==========================create table===========================
    table[0].set("ADD"   ,3,"18");    table[1].set("ADDF"  ,3,"58");
    table[2].set("ADDR"  ,2,"90");    table[3].set("AND"   ,3,"40");
    table[4].set("CLEAR" ,2,"B4");    table[5].set("COMP"  ,3,"28");
    table[6].set("COMPF" ,3,"88");    table[7].set("COMPFR",2,"A0");
    table[8].set("DIV"   ,3,"24");    table[9].set("DIVF"  ,3,"64");
    table[10].set("DIVFR" ,2,"9C");    table[11].set("FIX"   ,1,"C4");
    table[12].set("FLOAT" ,1,"C0");    table[13].set("HIO"   ,1,"F4");
    table[14].set("J"     ,3,"3C");    table[15].set("JEQ"   ,3,"30");
    table[16].set("JGT"   ,3,"34");    table[17].set("JLT"   ,3,"38");
    table[18].set("JSUB"  ,3,"48");    table[19].set("LDA"   ,3,"00");
    table[20].set("LDB"   ,3,"68");    table[21].set("LDCH"  ,3,"50");
    table[22].set("LDF"   ,3,"70");    table[23].set("LDL"   ,3,"08");
    table[24].set("LDS"   ,3,"6C");    table[25].set("LDT"   ,3,"74");
    table[26].set("LDX"   ,3,"04");    table[27].set("LPS"   ,3,"D0");
    table[28].set("MUL"   ,3,"20");    table[29].set("MULF"  ,3,"60");
    table[30].set("MULR"  ,2,"98");    table[31].set("NORM"  ,1,"C8");
    table[32].set("OR"    ,3,"44");    table[33].set("RD"    ,3,"D8");
    table[34].set("RMO"   ,2,"AC");    table[35].set("RSUB"  ,3,"4C");
    table[36].set("SHIFTL",2,"A4");    table[37].set("SHIFTR",2,"A8");
    table[38].set("SIO"   ,1,"F0");    table[39].set("SSK"   ,3,"EC");
    table[40].set("STA"   ,3,"OC");    table[41].set("STB"   ,3,"78");
    table[42].set("STCH"  ,3,"54");    table[43].set("STF"   ,3,"80");
    table[44].set("STI"   ,3,"D4");    table[45].set("STL"   ,3,"14");
    table[46].set("STS"   ,3,"7C");    table[47].set("STSW"  ,3,"E8");
    table[48].set("STT"   ,3,"84");    table[49].set("STX"   ,3,"10");
    table[50].set("SUB"   ,3,"1C");    table[51].set("SUBF"  ,3,"5C");
    table[52].set("SUBR"  ,2,"94");    table[53].set("SVC"   ,2,"B0");
    table[54].set("TD"    ,3,"E0");    table[55].set("TIO"   ,1,"F8");
    table[56].set("TIX"   ,3,"2C");    table[57].set("TIXR"  ,2,"B8");
    table[58].set("WD"    ,3,"DC");
    
}
int ModeTable::search(char *buff)
{
    for(int i=0;i<59;i++)
    {
        if (!strcmp(buff,table[i].getmode()))
        {
    
                table[i].show();
                //=============base16 to base2===========
                base2(*table[i].getop());
                for(int j=0;j<4;j++) op[j]=base2buff[j];
                base2(*(table[i].getop()+1));
                for(int j=0;j<4;j++) op[j+4]=base2buff[j];
                //=============return format=============
                return table[i].getformat();
        }
    }
    return 0;
}
void ModeTable::indication(char *buff)
{
   char temp[]={"nixbpe"};
   
   //==================base16 to base2===================   
   int flag=0;
   if(buff[0]=='#'||buff[0]=='@') flag=1; 
   for(int i=0;i<3;i++)
   {
            base2(buff[i+flag]);
            for(int j=0;j<4;j++) 
               disp[j+(i*4)]=base2buff[j];
   } 
   //=================show indication=====================
   
   cout<< "\nMode: ";
//==================judge indication=================
   if(buff[0]=='#'){
      cout <<"Immediate\n";
      strcpy(ind,"010000");
   
   }
   else if(buff[0]=='@') {
      cout <<"Indirect\n";
      strcpy(ind,"100000");

   }
   else{               
      if(buff[3]!='\0'&&buff[3]==','){
          cout <<"Indexed Direct\n";
          strcpy(ind,"111000");
    
          for(int i=0;i<6;i++)
          cout<<temp[i]<<" = "<<ind[i]<<" " ;
          show();
          
          cout<< "\nMode: Indexed PC Relative\n";
          strcpy(ind,"111010");
          
          for(int i=0;i<6;i++)
            cout<<temp[i]<<" = "<<ind[i]<<" " ;
          show();      
                
          cout<< "\nMode: Indexed Base Relative\n";
          strcpy(ind,"111100");
      }
      else{
          cout <<"Direct\n";
          strcpy(ind,"110000");
    
          for(int i=0;i<6;i++)
            cout<<temp[i]<<" = "<<ind[i]<<" " ;
          show();
          
          cout<< "\nMode: PC Relative\n";
          strcpy(ind,"110010");
          
          for(int i=0;i<6;i++)
            cout<<temp[i]<<" = "<<ind[i]<<" " ;
          show();      
                
          cout<< "\nMode: Base Relative\n";
          strcpy(ind,"110100"); 
      }     
   }
 
   for(int i=0;i<6;i++)
        cout<<temp[i]<<" = "<<ind[i]<<" " ;
   cout<<endl;
}

void ModeTable::base2(char buff)
{
    char temp[]={"0123456789ABCDEF"};
    int base16=0,i,j;
    //==================char to int====================
    for(i=0;i<16;i++)
        if(buff==temp[i])    base16=i;
    //=================base16 to base2=================
    for(i=0;i<4;i++){
        if((base16-pow(double(2),double(3-i)))>=0){
            base2buff[i]='1';
            base16-=int(pow(double(2),double(3-i)));
        }
        else
            base2buff[i]='0';
    }	
}

char* ModeTable::base16(char *buff)
{
    char temp[]={"0123456789ABCDEF"};
    
    for(int i=0,j=3,t=0;i<24;i++)
    {
       t+=(buff[i]-'0')*int(pow(double(2),double(j--)));
       if(i%4==3)
       {   
              hexbuff[i/4]=t;
              t=0;j=3;
       }
       
    }
    hexbuff[6]='\0';
    for(int i=0;i<6;i++)
        hexbuff[i]=temp[hexbuff[i]];
    return hexbuff;
}

void ModeTable::show()
{
      char mcode_2[25],hex[7];
      strcpy(mcode_2,op);
      strcpy(mcode_2+6,ind);
      strcat(mcode_2,disp);

      cout<<"\nMachine code(base2) :";
      for(int i=0;i<24;i++)
      {
            if(i%4==0) cout<<" ";
            cout<<mcode_2[i];
      }
       
      strcpy(hex,base16(mcode_2));
                   
      cout<<"\nMachine code(base16):";
      for(int i=0;i<6;i++)
      {
            if(i%2==0) cout<<" ";
            cout<<hex[i];
      }cout<<endl; 
}
