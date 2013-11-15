#include "deploy_map.h"
#include <windows.h>
void SetColor(unsigned short ForeColor,unsigned short BackGroundColor) 
//倒把计箇砞ㄏウ钡0/1/2把计
{ 
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);          //セㄒ块ㄒ
    SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor); 
};
deploy_map::deploy_map(int x,int y){
    row = x; col =y;
    sensor_num=0;
	list =  new int*[row];
	for(int i=0; i< row ; i++){
		list[i]=new int[col];
		memset(list[i],0,sizeof(int[col]));
	}
}
deploy_map::~deploy_map(){
    for(int i=0; i< row ; i++){
        delete [] list[i];
    }
    delete [] list;
}

bool deploy_map::Is_deploy(int x,int y){
    return list[x][y]>=2 ? true : false;    
}
bool deploy_map::Is_Coverage(int x,int y){
    return list[x][y]> 0 ? true : false;
}
int deploy_map::Get_row(){return row;}
int deploy_map::Get_col(){return col;}
/*************************************************/
//compute two circle if coverage grid point (x,y)
/*************************************************/
void deploy_map::Reset(){
    sensor_num=0;
    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
        list[i][j]=0;
}
void deploy_map::deploy_sensor(int x,int y){

    if(!Is_deploy(x,y))    sensor_num++;
    list[x][y]=2;
    for(set<int>::iterator p=n_table->c_list[x*col+y].begin();
        p!=n_table->c_list[x*col+y].end();
        p++){
            int i=*p/col,j=*p%col;
            if(list[i][j]<1)    list[i][j]=1;
        }
}
void deploy_map::combine_map(class deploy_map p){
    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
        if(p.Is_deploy(i,j))
            deploy_sensor(i,j);
    }
}

void deploy_map::AssignMap(class deploy_map p){
		sensor_num=p.sensor_num;
		for(int i=0;i<row;i++)
        for(int j=0;j<col;j++){
            list[i][j]=p.list[i][j];
        }
}
void deploy_map::output_map(char *filename){
	ofstream fout (filename,ios::app);
    fout<<"sensor num= "<<sensor_num<<endl;

	for(int i=0 ; i< row ; i++){
		for(int j=0 ; j< col ; j++){
			fout << list[i][j]<<" ";
		}
		fout << endl;
	}
	fout << endl;	
	fout.close();
}
void deploy_map::show_map(class Grid *c_map){
    cout<<"sensor num= "<<sensor_num<<endl;

	for(int i=0 ; i< row ; i++){
		for(int j=0 ; j< col ; j++){
            if(Is_deploy(i,j))        SetColor(20,25);
            else if(Is_Coverage(i,j)) SetColor(20,21);
            if(c_map->IsCritical(i,j)){cout<<"1";}
            else if(!c_map->IsLink(i,j)){cout<<"*";}
            else                      {cout<<"0";}            
 
            SetColor(7,0);
            cout<<" ";
		}
		cout << endl;
	}
	cout << endl;	    
}
