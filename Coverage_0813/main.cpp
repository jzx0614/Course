#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "globals.h"
#include "grid.h"
#include "msc.h"
//#include "dp_algorithm.h"
#include "neighbor_table.h"
#include "relay_node.h"
#include "spider.h"
#include "hop_count.h"

int DEBUG=1;
bool IsObstacle;
char out_filename[100];
class neighbor_table *n_table;


void read_ini(double *RS,vector<double> *RT_list,int *type,int *method_mode,int *map_num){
    string Str;
    int RT_NUM=0;
    
    ifstream fin ("coverage.ini");
    while(fin >> Str){
        if(Str.find("#")==-1){
            if(Str == "RS")
                fin >> *RS;
            else if(Str == "RT_NUM")
                fin >> RT_NUM;
            else if(Str == "RT"){
                double temp;
                for(int i=0;i<RT_NUM;i++){
                    fin >> temp;
                    (*RT_list).push_back(temp);
                }
            }
            else if(Str == "DEBUG")
                fin >> DEBUG;
            else if(Str == "MAP_NUMBER")
                fin >> *map_num;
            else if(Str == "C_MAP_TYPE")
                fin >> *type;            
            else if(Str == "METHOD_MODE")
                fin >> *method_mode;            
            else if(Str == "ISOBSTACLE")
                fin >> IsObstacle;
        }
    }
    fin.close();

}
int main(int argc, char *argv[])
{
    double RS,RT;
    vector<double> RT_list;
    int    type,method_mode,map_num;
    time_t t=time(NULL);

    read_ini(&RS,&RT_list,&type,&method_mode,&map_num);
 
 
    for(int map_id=1;map_id<=map_num;map_id++)
    for(int rt_i=0;rt_i < RT_list.size();rt_i++){

        Grid *critical_map = new class Grid(map_id,IsObstacle); 

        if(!critical_map->Create_Map(type)) continue;

       n_table=new class neighbor_table(    critical_map->Get_row(),
                                            critical_map->Get_col(),
                                            RS,
                                            RT_list[rt_i],
                                            critical_map,
                                            IsObstacle);

        char path[100],envvar[]="PATH";
        char target[]="map_deployment";
        int iteration=0;
        do{                       //§ä´M[iteration]_map_deployment.txt¤¤ªºiteration­È
            sprintf(out_filename,"%d_%d_%s.txt",map_id,++iteration,target);
            _searchenv (out_filename,envvar,path);
        }while(*path!='\0');    
    
        ofstream fout(out_filename);
        fout <<"RS="<<RS<<" RT="<<RT_list[rt_i]<<endl<<endl;
        fout.close();

        if(method_mode == 0){
    //            class DP_Algorithm *DP = new class DP_Algorithm(critical_map);
    //           DP->Construct_DP_Table();
        }
        else if(method_mode == 3){
            int i,j;
            class spider *spider_deploy = new class spider(int(4*ceil(RS/RT_list[rt_i])+2));

            spider_deploy->Embedded_to_Graph(critical_map);
            cout<<"==============Embedded to Graph Finish==============\n";           
    
            spider_deploy->Construct_AP_distance();
            cout<<"==============Construct_adjacency_matrix Finish==============\n";
    
            spider_deploy->Algorithm();
    
            if(DEBUG) spider_deploy->Graph_to_Deploy()->show_map(critical_map);
            spider_deploy->Graph_to_Deploy()->output_map(out_filename);

            delete spider_deploy;
        }
        else{
            class MSC *min_set = new class MSC(critical_map);
            min_set->Construct_min_set_cover();
            cout<<"Minimum Set Cover:\n";
            if(DEBUG){ 
                min_set->Get_MSC_Map()->show_map(critical_map);
                min_set->Get_MSC_Map()->output_map(out_filename);
            }
    
            if(method_mode == 1){
                class Relay_node *relay = new class Relay_node(min_set->Get_MSC_Map());
                relay->Construct_adjacency_matrix();
                cout<<"==============Construct_adjacency_matrix Finish==============\n";
                relay->MST();
                cout<<"==============Minimum Spanning Tree Finish==============\n";
                relay->Connect_MST();
                cout<<"Relay_node deployment:\n";
                if(DEBUG) relay->Get_Map()->show_map(critical_map);
                relay->Get_Map()->output_map(out_filename);
                delete relay;
            }
            else if(method_mode == 2){
                class hop_count *hop = new class hop_count(min_set->Get_MSC_Map());
                hop->Main_Method();
                cout<<"Hop_count deployment:\n";
                if(DEBUG) hop->Get_hop_map()->show_map(critical_map);
                hop->Get_hop_map()->output_map(out_filename);
                delete hop;
            }
            delete min_set;
        }
        cout<<endl;

        delete critical_map;
        delete n_table;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
