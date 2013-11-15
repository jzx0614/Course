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
        int c_table[5][5];
        int o_table[5][5];

};
Bingo::Bingo()
{
    memset(c_table,0,sizeof(c_table));
    
    time_t t;
    srand(time(&t));
    
    init(c_table);
    memcpy(o_table,c_table,sizeof(c_table));
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
		if(value==c_table[i][j]){
    		c_table[i][j]=0;
    	    flag=true;	
		}		
    }
    return flag;
}
int Bingo::linenum()
{

    int c_num=linenum(c_table);
	
	
	cout<<"Computer line is "<<c_num<<endl;
	if(c_num>=5){	
       cout<<"\nComputer Bingo.\n";
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
//		cout<<"     Player:                Computer:\n\n";
		cout<<"     Computer:              Initial_table\n\n";
	    for(int i=0;i<5;i++){
	    	/*for(int j=0;j<5;j++){
	    		if(p_table[i][j]==0) printf("  줚");
				else				 printf("  %2d",p_table[i][j]);
			}
			cout<<"  |";*/
/*	        for(int j=0;j<5;j++){
     	   		if(c_table[i][j]==0) printf("    ");
				else				 printf("  %2d",c_table[i][j]);
			}*/
	        for(int j=0;j<5;j++){
     	   		if(!c_table[i][j]==0) printf("    ");
				else				 printf("  %2d",o_table[i][j]);
			}			
			cout<<"  |";
	    	for(int j=0;j<5;j++){
	    		if(o_table[i][j]==0) printf("  》");
				else				 printf("  %2d",o_table[i][j]);
			}   			
    		cout<<endl;
    	}        
    	cout<<endl;
}
int main(void)
{
	int value;
	char f;
	class Bingo hw5;
	do{
        cout<<"Which is First?\nComputer(c) or Player(p): ";
        cin >>f;
    	do{
    	    if(f=='c'){
                value=hw5.computer_select();
                hw5.Input(value);
                hw5.show();
        		cout<<"Computer Select "<<value<<"\n\n";        
        		if((value=hw5.linenum())==0) break;
                f='p';      
            }
            do{
                cout<<"\nInput a value: ";
        		cin>>value;
            }while(!hw5.Input(value));                    
            hw5.show();            
       
    		value=hw5.linenum();
            f='c';
     	}while(value!=0);
 	     cout<<"\n(1)Play Again or (0)Exit : ";
     	 cin >>value;
         system("cls");
 	}while(value!=0); 	
 	system("PAUSE");
}
