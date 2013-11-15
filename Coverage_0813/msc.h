#ifndef _MSC_H_
#define _MSC_H_

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
using namespace std;

#include "grid.h"
#include "deploy_map.h"
#include "globals.h"
#include "neighbor_table.h"

typedef struct node_information{
    int x,y;
    int weight;
    set<int> cover_wnode;
}node;
class MSC{
    public:
        MSC(class Grid *);
        ~MSC();
        int Find_max_set();
        void Construct_min_set_cover();
        void refresh_set(int);
        class deploy_map * Get_MSC_Map();
        
    private:
        class Grid *c_map;
        class deploy_map *msc_map;
        int row,col,c_num;
        node *list;
};

#endif  /*_MSC_H_*/
