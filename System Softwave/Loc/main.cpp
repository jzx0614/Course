#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;
#include "addressing.h"
#include "modetable.h"

void show(long t,char *buff)
{
    long tmp;
    for(int i=3;i>=0;i--){
        tmp=t>>i*4;
        if(tmp==0) 
                cout<<tmp;
        else{
          printf("%X\t%s\n",t,buff);
          break;  
        }    
    }    
}
int main(int argc, char *argv[])
{
  class ModeTable loc;
  char filename[10],buf[30],tmp[10],opcode[10];
  cout<< "Input filename: ";
  cin >> filename;
  ifstream fin(filename);
  long LOCCTR=0;
  printf("\nLoc\tSource statement\n");
  
  memset(buf,0,strlen(buf));
  fin.getline(buf,30);

  sscanf(buf,"%s\t%s\t%X",tmp,opcode,&LOCCTR);
  if(strcmp(opcode,"START")!=0){
      LOCCTR=0;
      cout<<buf<<endl;     
  }
  else 
      show(LOCCTR,buf);

  while(!fin.eof()){
     memset(buf,0,strlen(buf));
     fin.getline(buf,30);
     show(LOCCTR,buf);
     sscanf(buf,"\t%s",opcode);
     if(strcmp(opcode,"END")==0)break;
     if(loc.search(opcode)==0)
          sscanf(buf,"%s\t%s",opcode);
     LOCCTR+=loc.search(opcode);

  }  
  system("PAUSE");	
  return 0;
}
