#ifndef _GRID_H_
#define _GRID_H_

#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

class Grid{
	public:
		Grid(int,bool);
        ~Grid();
        bool Create_Map(int);
		bool IsCritical(int,int);
        bool IsVert(int,int);
        bool IsHori(int,int);
        bool IsLink(int,int);

		int Get_Critical_Num();
		int Get_row();
		int Get_col();

        int Random_propagate(int,int,int,int); //7_23 kwc propagate....
        void Random_broadcast(int,int,int);

    protected:

	    int  Initgrid(int,double);    
		void showgrid();
        	    
		int **list;
        int **vert;
        int **hori;
		int row,col;

        int c_num;  //the number of critical field
        int map_id;
        bool IsObst;
};
#endif  /*_GRID_H_*/
