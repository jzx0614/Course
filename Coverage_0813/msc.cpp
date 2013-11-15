#include "msc.h"


MSC::MSC(class Grid *map){
    c_map = map;
    row   = c_map->Get_row();
    col   = c_map->Get_col();  
    c_num = c_map->Get_Critical_Num();
    msc_map = new class deploy_map(row,col);


    list = new node[row*col];
    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
        list[i*col+j].x=i;
        list[i*col+j].y=j;
        list[i*col+j].weight=0;
    }
    // 需改成 去搜 list[p] 是否 cover (x,y) 
    for(int x=0;x<row;x++)
    for(int y=0;y<col;y++)
        if(c_map->IsCritical(x,y)){
            for(set<int>::iterator p=n_table->c_list[x*col+y].begin();
                p!=n_table->c_list[x*col+y].end();
                p++){                    
                    list[*p].cover_wnode.insert(x*col+y);
                    list[*p].weight=list[*p].cover_wnode.size();

            }
        }

}
MSC::~MSC(){
    delete [] list;
    delete  msc_map;
}
int MSC::Find_max_set(){
    int maxweight=0,pos=-1;
    for(int i=0;i<row*col;i++){
        if(list[i].weight > maxweight){
            maxweight=list[i].weight;
            pos=i;
        }
    }
    return pos;
}
void MSC::Construct_min_set_cover(){
    int p;

    while((p=Find_max_set())!=-1){
        msc_map->deploy_sensor(list[p].x,list[p].y);
        refresh_set(p);
    }
}
void MSC::refresh_set(int pos){
    set<int>::iterator p;
    set<int>::iterator key;

    for(p=list[pos].cover_wnode.begin();p!=list[pos].cover_wnode.end();p++)
    for(int i=0;i<row*col;i++){
        if(i!=pos){             
            key = list[i].cover_wnode.find(*p);
            if( key!=list[i].cover_wnode.end() ){          
                list[i].cover_wnode.erase(key);
                list[i].weight--;
            }
        }
    } 
    list[pos].cover_wnode.clear();
    list[pos].weight=0;
}
class deploy_map * MSC::Get_MSC_Map(){
    return msc_map;
}
