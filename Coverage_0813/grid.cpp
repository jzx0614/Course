#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include "grid.h"
#define DEBUG   0
/*
  type = 0 為 讀檔
  type > 0 為 隨機產生 Map 
*/
Grid::Grid(int id,bool Obst){
    map_id = id;
    IsObst = Obst;
}

Grid::~Grid(){
    for(int i=0; i< row ; i++)
        delete [] list[i];
    delete [] list;
}
bool Grid::Create_Map(int type){
    double prob;  
    c_num=0; 
    ifstream fin;
    if(type==0){
        char input_filename[20];
        if(!IsObst)
            sprintf(input_filename,"%d_input_field.txt",map_id);
        else
            sprintf(input_filename,"o_%d_input_field.txt",map_id);
        fin.open(input_filename);
        if(!fin) {
            cerr << "Error opening input stream " << input_filename<<endl;
            
            return false;
        }         
        fin >> row >> col;
    }
    else{         
                  
    	cout<<"Please Set Grid size and probability(row col p_num p_pro): ";
	    cin >>row>>col>>prob;
    }
       
	list =  new int*[row];
    vert =  new int*[row];
    hori =  new int*[row];
	for(int i=0; i< row ; i++){
		list[i] =  new int[col];
        vert[i] =  new int[col-1];
        if(i < row-1 ){
            hori[i] =  new int[col];
            memset(hori[i],0,sizeof(int[col]));
        }
		memset(list[i],0,sizeof(int[col]));
		memset(vert[i],0,sizeof(int[col-1]));
	}
    
    if(type == 0){
		for(int i=0 ; i< row ; i++)
		for(int j=0 ; j< col ; j++)
                    fin >> list[i][j];

        if(IsObst){
        	for(int i=0 ; i< row ; i++)
        	for(int j=0 ; j< col-1 ; j++)
                fin >>vert[i][j];
        
        	for(int i=0 ; i< row-1 ; i++)
        	for(int j=0 ; j< col ; j++)
                fin >>hori[i][j];
            fin.close();     
        }
    }
    else{        
        Initgrid(type,prob);
    }

     for(int i=0;i<row;i++)
     for(int j=0;j<col;j++)
             if(list[i][j]>0) c_num++;    
    showgrid();
    return true;
}
bool Grid::IsCritical(int x,int y){
     return list[x][y]==1 ? true : false;
}
bool Grid::IsVert(int x,int y){
    if( x<0 || x >= row || y<0 || y>=col) return false;
    else if(IsObst)                     return vert[x][y]==1 ? true : false;
    else                                return false;
}
bool Grid::IsHori(int x,int y){
    if( x<0 || x >= row || y<0 || y>=col) return false;
    if(IsObst)                          return hori[x][y]==1 ? true : false;
    else                                return false;
}
bool Grid::IsLink(int x,int y){
     if( x<0 || x >= row || y<0 || y>=col) return false;
     else                                return list[x][y]== -1 ? false : true;
}
int Grid::Get_row(){return row;}
int Grid::Get_col(){return col;}

int Grid::Get_Critical_Num(){
     return c_num;
}
/******************************************************************************
產生 Critical Field 的Map
type = 1 為 隨機產生 每個 grid 為 critical的機率為 prob
type = 2 為 隨機產生 整個 2D mesh 有 total * prob  個數的 Critical Field 
******************************************************************************/
int Grid::Initgrid(int type,double prob){
	int prob_int = (int)ceil(prob*100);
	srand(time(NULL));
    if(type==1){
		for(int i=0 ; i< row ; i++)
		for(int j=0 ; j< col ; j++){				
				int r_value=rand()%100+1;
				if(r_value <= prob_int )
					list[i][j]=1;
        }
	}
	else if(type==2){
	     for(int i=0; i< ceil(prob*row*col); i++){
                 int random_x,random_y;
                 do{
                    random_x=rand()%row;
                    random_y=rand()%col;
                 }while(list[random_x][random_y]);
                 list[random_x][random_y]=1;
         }
	}
    else if(type ==3){
	     for(int i=0; i< ceil(prob*row*col); i++){
                 int random_x,random_y;
                 do{
                    random_x=rand()%row;
                    random_y=rand()%col;
                 }while(list[random_x][random_y]);
                 list[random_x][random_y]=1;
                 //Random_broadcast(random_x,random_y,rand()%(col/2));
                 Random_broadcast(random_x,random_y,col/8);
         }
    }
    else if(type ==4){
        int total_num = (int)ceil(prob*row*col);
        double prob_c;
        cin >>  prob_c;
        for(int count_num=total_num; count_num >0 ;){
            int random_x,random_y;
            do{
                random_x=rand()%row;
                random_y=rand()%col;
            }while(list[random_x][random_y]);
            list[random_x][random_y]=1;        
            count_num--;    
            count_num = Random_propagate(random_x,random_y,(int)ceil(prob_c*1000),count_num);
        }
    }
    else if(type==5){
    	
    }
	return 0;
}
int Grid::Random_propagate(int x,int y,int prob,int k){
    int direct[2][4]={{-1,0,1,0},{0,1,0,-1}};
    int pos[2][4];
    for(int i=0;i<4;i++){
        pos[0][i]=x+direct[0][i];
        pos[1][i]=y+direct[1][i];
    }
    for(int i=0;i<4;i++){
    	if(k==0) break;
        if( 0<=pos[0][i]&&pos[0][i]<row && 0<=pos[1][i]&&pos[1][i]<col)
            if(list[pos[0][i]][pos[1][i]]==0 && rand()%1000 < prob){
                list[pos[0][i]][pos[1][i]] = 1;                
                k=Random_propagate(pos[0][i],pos[1][i],prob,--k);
            }       
    }
    return k;
}
void Grid::Random_broadcast(int x,int y,int k){
    int direct[2][4]={{-1,0,1,0},{0,1,0,-1}};
    if(k!=0){
        int pos[2][4];
        for(int i=0;i<4;i++){
            pos[0][i]=x+direct[0][i];
            pos[1][i]=y+direct[1][i];
        }
        for(int i=0;i<4;i++)
            if( 0<=pos[0][i]&&pos[0][i]<row && 0<=pos[1][i]&&pos[1][i]<col)
                if(list[pos[0][i]][pos[1][i]]==0 && rand()%3 > 0){
                    list[pos[0][i]][pos[1][i]] = 1;
                    Random_broadcast(pos[0][i],pos[1][i],rand()%k);
                }        
    }
}
/******************************************************************************
  顯示Map到STDIN及coverage.log中 
******************************************************************************/
void Grid::showgrid(){
  
     char path[100],filename[100],envvar[]="PATH";
     char target[]="output_field";
     int iteration=0;
     do{                       //找尋[iteration]_output_filed.txt中的iteration值
        sprintf(filename,"%d_%d_%s.txt",map_id,++iteration,target);
        _searchenv (filename,envvar,path);
     }while(*path!='\0');


    
    cout<<"==============Create Critical Map Finish.==============\n";    
 
	ofstream fout (filename);
	fout << row <<" "<<col<<" "<<c_num<<endl;
//	fout << row <<" "<<col<<" "<<endl;
	for(int i=0 ; i< row ; i++){
		for(int j=0 ; j< col ; j++){
			fout << setw(2)<<list[i][j]<<" ";
		}
		fout << endl;
	}
    fout << endl;

    if(IsObst){        
    	for(int i=0 ; i< row ; i++){
    	   for(int j=0 ; j< col-1 ; j++)
    		  fout << vert[i][j]<<" ";
           fout <<endl;
        }
        fout <<endl;
    
    	for(int i=0 ; i< row-1 ; i++){
    	   for(int j=0 ; j< col ; j++)
                fout << hori[i][j]<<" ";
           fout <<endl;        
        }
    }
  	fout.close();

    if(DEBUG){
    	for(int i=0 ; i< row ; i++){
    		for(int j=0 ; j< col ; j++){
    			if(j==0)cout<<"| ";
    			if(list[i][j]<0) cout<<"* ";
                else if(list[i][j]==0) cout <<"  ";
                else             cout << list[i][j]<<" ";
           }
    		cout << " |\n";
    	}
        cout << endl;
        if(IsObst){       
        	for(int i=0 ; i< row ; i++){
        	   for(int j=0 ; j< col-1 ; j++)
        		  cout <<vert[i][j]<<" ";              
               cout <<endl;           
            }
            cout <<endl;  
        	for(int i=0 ; i< row-1 ; i++){
        	   for(int j=0 ; j< col ; j++)
                    cout << hori[i][j]<<" ";
               cout <<endl;        
           }
       }
    }
}


