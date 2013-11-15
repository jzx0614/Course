#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
#include <stdio.h>
class Bingo
{
    public: 
    	Bingo();   
    	void init(int [5][5]);
            	
    	bool Input(int);
    	
    	int linenum();
    	int linenum(int [5][5]);
    	
    	int computer_select();
    	
    	void show();
    	void show(int list[5][5]);
    private:
        int exp(int,int);
        int exptable(int);
        int p_table[5][5],c_table[5][5];

};
Bingo::Bingo()
{
    memset(p_table,0,sizeof(p_table));
    memset(c_table,0,sizeof(c_table));
    
    time_t t;
    srand(time(&t));
    
    init(p_table);
    init(c_table);
}

void Bingo::init(int list[5][5])
{
    int value;
    bool buffnum[25];

    memset(buffnum,0,sizeof(buffnum));
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
                do{               
                value=rand()%25;
                }while(buffnum[value]==1);
                list[i][j]=value+1;
                buffnum[value]=1;
        }
}
bool Bingo::Input(int value)
{
    bool flag=false;
 	for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
    {
    	if(value==p_table[i][j])
    		p_table[i][j]=0;
		if(value==c_table[i][j]){
    		c_table[i][j]=0;
    	    flag=true;	
		}		
    }
    return flag;
}
int Bingo::linenum()
{
	int p_num=linenum(p_table);
    int c_num=linenum(c_table);
	
	
	cout<<"Player line is "<<p_num<<"\tComputer line is "<<c_num<<endl;
	if(c_num>=5)	cout<<"\nComputer Bingo.\n";
	if(p_num>=5)	cout<<"\nPlayer Bingo.\n";

	if(p_num>=5||c_num>=5) {
         init(p_table);
         init(c_table);
         return 0;
    } 
    return 1;
}
int Bingo::linenum(int list[5][5])
{
	int row,col,right=0,left=0,num=0;

 	for(int i=0;i<5;i++){
 		row=0,col=0;
		for(int j=0;j<5;j++){
			if(!list[i][j]) row+=1;
			if(!list[j][i]) col+=1;
		}
		if(!list[i][i])   left+=1;
		if(!list[i][4-i]) right+=1;
		if(row==5) num+=1;
		if(col==5) num+=1;
	}   
	if(left==5) num+=1;
	if(right==5) num+=1;

	return num;
}
int Bingo::computer_select()
{
    int exp_table[5][5],max=0;
    memset(exp_table,0,sizeof(exp_table));
    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++){
        if(c_table[i][j]==0) 
           exp_table[i][j]=0;
        else    
           exp_table[i][j]=exp(i,j);
        if(max<=exp_table[i][j])
              max=exp_table[i][j];
        }    
 
//    for(int i=0;i<5;i++){
//    for(int j=0;j<5;j++) 
//        printf("%4d",exp_table[i][j]);
//    cout<<endl;    
//    }     
//    system("PAUSE");   
  
    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
        if(exp_table[i][j]==max)
            return c_table[i][j];
 
}
int Bingo::exp(int x,int y)
{
	int row=0,col=0,right=0,left=0,num=0;
    int temp=c_table[x][y];

    c_table[x][y]=0;
    
    for(int i=0;i<5;i++){
        if(!c_table[i][y]) row+=1; //어퐑 
        if(!c_table[x][i]) col+=1; //そ퐑 
        if(x==y)
            if(!c_table[i][i])   left+=1;  // \ 퐑 
    		if(!c_table[i][4-i]) right+=1; // / 퐑      
    }
    c_table[x][y]=temp;   
    num=exptable(row)+exptable(col)+exptable(left)+exptable(right);

	return num;         
}
int Bingo::exptable(int value)
{
    int Ret;
    switch(value)
    {
        case 1:  Ret=1;  break; 
        case 2:  Ret=4;  break;
        case 3:  Ret=7;  break;
        case 4:  Ret=15; break;
        case 5:  Ret=31; break;
        default: Ret=0;  break;
    }
    return Ret;
}
void Bingo::show()
{
        system("cls");    
		cout<<"     Player:                Computer:\n\n";
	    for(int i=0;i<5;i++){
	    	for(int j=0;j<5;j++){
	    		if(p_table[i][j]==0) printf("  줚");
				else				 printf("  %2d",p_table[i][j]);
			}
    		cout<<endl;
    	}        
    	cout<<endl;
}
int main(void)
{
	int value;
	class Bingo hw5;

	do{
        hw5.show();	    
        
        do{
        cout<<"\nInput a value: ";
		cin>>value;

        }while(!hw5.Input(value));                    
        hw5.show();            
   
		if(!hw5.linenum()){
          cout<<"\n(1)Play Again.\n(0)exit\n\nInput a value: ";
          cin>>value;
          continue;
        }

 	}while(value!=0);
}
