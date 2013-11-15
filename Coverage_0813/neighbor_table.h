// Class automatically generated by Dev-C++ New Class wizard

#ifndef NEIGHBOR_TABLE_H
#define NEIGHBOR_TABLE_H

#include "grid.h"
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

// No description
class neighbor_table
{
	public:
		// class constructor
		neighbor_table(int,int,double,double,Grid*,bool);

		// class destructor
		~neighbor_table();

        bool Is_P_neighbor(int,int,int,int);
        bool Is_Sight(double,double,double,double);
        int Compute_cover_grid(int,int,int,int);
        void Construct_neighbor_table();

        set<int> *n_list;
        set<int> *c_list;
    private:
        bool IsObstacle;
        int row,col;
        double RS,RT;
        Grid *map;
};

#endif // NEIGHBOR_TABLE_H