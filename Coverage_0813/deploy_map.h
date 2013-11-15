#ifndef _DEPLOY_MAP_H_
#define _DEPLOY_MAP_H_

#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
using namespace std;
#include "globals.h"
#include "neighbor_table.h"
#include "grid.h"

class deploy_map{
	public:
		deploy_map(int,int);
        ~deploy_map();

        bool Is_deploy(int,int);
        bool Is_Coverage(int,int);
      
        int Get_row();
        int Get_col();

        void Reset();
        void deploy_sensor(int,int); // add new sensor in Map
        void combine_map(class deploy_map);
        void AssignMap(class deploy_map);
        void output_map(char *); 
        void show_map(class Grid *);       

		long sensor_num;  // total deploy number
	private:
		int **list;      // map deploy ªº±¡§Î
		int row,col;
};
#endif  /*_DEPLOY_MAP_H_*/
