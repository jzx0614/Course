#ifndef _DP_Algorithm_H_
#define _DP_Algorithm_H_

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>

using namespace std;

#include "globals.h"
#include "grid.h"
#include "deploy_map.h"

class DP_Algorithm{
      public:
            DP_Algorithm(class Grid *);
            bool Is_PMAP_neighbor(int q_x,int q_y,class deploy_map *);

            int  Find_min_weight(int);
            int  Compute_weight(class deploy_map *);


            void show_weight_Table(int);
            void show_max_kmap(int,bool);

            void Construct_DP_Table(); 
      private:
              
            int row,col,c_num;
            int ans_x,ans_y;
            class Grid *c_map;
            int ***W;          
            deploy_map ****M;
};


#endif  /*_DP_Algorithm_H_*/
