#include "dp_algorithm.h"



/*************************************************/
//Initial Object data.
/*************************************************/
DP_Algorithm::DP_Algorithm(class Grid *map){
    
    c_map = map;
    row   = c_map->Get_row();
    col   = c_map->Get_col();  
    c_num = c_map->Get_Critical_Num();
    ans_x=0;
    ans_y=0;
        

    W= new int **[row];     
    M= new class deploy_map ***[row];   // initial Map M[row][col]
    for(int i=0; i< row ; i++){
       W[i]=new int *[col];
       M[i]=new class deploy_map **[col];
        for(int j=0; j<col ; j++){
            W[i][j]=new int[row*col];
            M[i][j]=new class deploy_map *[int(row*col)];
            for(int k=0;k<row*col;k++){
                class deploy_map *p = new class deploy_map(row,col);
                W[i][j][k] = 0;
                M[i][j][k] = p;
            }

        }
    }      
}

/*************************************************/
//check neighbor between point p and point q
/*************************************************/
/*bool DP_Algorithm::Is_P_neighbor(int p_x,int p_y,int q_x,int q_y){
    if(p_x == q_x && p_y == q_y) return false;
    double distance =  pow(pow((double)(p_x-q_x),2.0)+( pow((double)(p_y-q_y),2.0)),0.5);
    return (distance <= RT) ? true : false;
}*/
bool DP_Algorithm::Is_PMAP_neighbor(int q_x,int q_y,class deploy_map *p){

    if(p->Is_deploy(q_x,q_y)) return false;


    for(set<int>::iterator iter=n_table->n_list[q_x*row+q_y].begin();
        iter!=n_table->n_list[q_x*row+q_y].end();
        iter++){
        if(p->Is_deploy(*iter/row,*iter%col))
             return true;
    }
    return false;
}
int  DP_Algorithm::Find_min_weight(int k){
    int minweight=W[0][0][k];
    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
        if(W[i][j][k]<minweight){
            minweight=W[i][j][k];
        }            
    return minweight;     
}



int  DP_Algorithm::Compute_weight(class deploy_map *p){
 
    int weight=0;
    for(int i=0;i<row;i++)       //Find RS Field point
    for(int j=0;j<col;j++)
        if(c_map->IsCritical(i,j) && p->Is_Coverage(i,j)){
                weight++;
        }
    return weight;
}

void DP_Algorithm::Construct_DP_Table(){
    int k=1;
    time_t t=time(NULL);
	cout << ctime(&t);
    class deploy_map *temp = new deploy_map(row,col);

	for(int i=0;i<row;i++)	
    for(int j=0; j<col ; j++){
        M[i][j][0]->deploy_sensor(i,j);
        W[i][j][0]=Compute_weight(M[i][j][0]);
        //W(p,1)=0+W(p,M(p,0))
    }

    for(int minweight=0; minweight < c_num ; k++){  

        for(int i=0;i<row;i++)
        for(int j=0;j<col;j++) //each all grid point p
        {
            W[i][j][k]= W[i][j][k-1];     //reset M[i][j] = 0
            M[i][j][k]->AssignMap(*M[i][j][k-1]);

            bool flag=false;
      
            for(set<int>::iterator p=n_table->n_list[i*row+j].begin();
                p!=n_table->n_list[i*row+j].end();p++){
                    int x=*p/row,y=*p%col;
                    for(int z=0;z<k;z++){
                        if(W[x][y][k-(z+1)]+W[i][j][z] >= W[i][j][k]){
                            temp->Reset();
                            temp->AssignMap(*M[x][y][k-(z+1)]);
                            temp->combine_map(*M[i][j][z]);
                            int temp_weight = Compute_weight(temp);
                            if( (W[i][j][k] < temp_weight)||          
                                (W[i][j][k] == temp_weight &&
                                 M[i][j][k]->sensor_num > temp->sensor_num )){

                                M[i][j][k] ->AssignMap(*temp);
                                W[i][j][k] = temp_weight;
                                //W(p,k) = W(q,k-1) + W(p, M(q,k-1))
                                flag=true;
                            }            
                        }
                    }  
            }
            if(!flag){
                for(int x=0;x<row;x++)                      //for all grid q
                for(int y=0;y<col;y++)
                if(Is_PMAP_neighbor(x,y,M[i][j][k-1])){
                    temp->Reset();
                    temp->AssignMap(*M[i][j][k-1]);
                    temp->combine_map(*M[x][y][0]);
                    int temp_weight = Compute_weight(temp);
                    if( (W[i][j][k] < temp_weight)||          
                        (W[i][j][k] == temp_weight &&
                         M[i][j][k]->sensor_num > temp->sensor_num )){

                        M[i][j][k] ->AssignMap(*temp);
                        W[i][j][k] = temp_weight;
                        //W(p,k) = W(q,k-1) + W(p, M(q,k-1))
                    }                                                           
                }
            }            
        }

        minweight=Find_min_weight(k);

        show_weight_Table(k);
        if(DEBUG)show_max_kmap(k,DEBUG);    
    }
    if(DEBUG ==0 )show_max_kmap(k-1,true);
    delete temp;
}

/*************************************************/
// Output M(p,k)   for all grid point p
/*************************************************/
void DP_Algorithm::show_weight_Table(int k){
    system("cls");

    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
        if((W[ans_x][ans_y][k] <  W[i][j][k]) ||
           (W[ans_x][ans_y][k] == W[i][j][k]  &&
            M[ans_x][ans_y][k]->sensor_num >  M[i][j][k]->sensor_num)   ){            
            ans_x=i;ans_y=j;
        }

    cout <<"M(("<<ans_x<<","<<ans_y<<"),"<<k+1<<")";       

    cout <<" sensor_num= "<<M[ans_x][ans_y][k]->sensor_num;
    cout <<" weight= "<<W[ans_x][ans_y][k]<<endl;
    if(DEBUG){
        cout<<"Weight Table:\n";
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                cout<<setw(2)<<W[i][j][k]<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                cout<<setw(2)<<M[i][j][k]->sensor_num<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
}


void DP_Algorithm::show_max_kmap(int k,bool IS_W_FILE){
    time_t t=time(NULL);
	cout << ctime(&t);
            
    M[ans_x][ans_y][k]->show_map(c_map);
          
    if(IS_W_FILE){
        ofstream fout (out_filename,ios::app);
        fout << ctime(&t);
        fout << "k = "<< k+1 <<" M(("<<ans_x<<","<<ans_y<<"),"<<k<<")\n";
        fout.close();
        M[ans_x][ans_y][k]->output_map(out_filename);
    }
}
