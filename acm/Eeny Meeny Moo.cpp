//440
//¤G¸ê¤T¥Ò  Â²§Ó°a 
#include<iostream>
using namespace std;
int main(void)
{
    int table[2][150];
    int i,j,n;
    while(cin >>n){
        if(n==0) break;
        for(i=2;;i++){
           for(j=0;j<n;j++){
              if(j==0)table[0][j]=1;
              else table[0][j]=0;
              if (j+1==n) table[1][j]=1;
              else table[1][j]=j+1;
           }
 
           int time,people,position,b_pos;
           for(time=1,people=1,position=1;people<n-1;position=table[1][position],time++)
           {  
              if(time==i){   
                 if(!table[0][position]){
                    if(position==1) {
                       table[0][1]=1; 
                       break;
                    }
                    else{
                       table[0][position]=1;
                       table[1][b_pos]=table[1][position];
                       people++;
                       time=0;
                    }
                 }
                 else break;
              }b_pos=position;
           }
           if(!table[0][1])break;
        }  cout <<i <<endl;
    }
}
