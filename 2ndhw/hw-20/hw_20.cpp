#include <iostream>
using namespace std;
class cube
{
	public:
		int set(int ,int ,int );
		void area1() ;
		void area2() ;		
	private:
		int length,width,high;
};

int  cube::set (int temp1,int temp2,int temp3)
{  
	if (temp1>0&&temp2>0&&temp3>0) 
		{ length =temp1; width=temp2; high=temp3; return 0;}
	else
		{ cout << "\nError num . \n\n"; return -1;}
}

void  cube::area1 (void)
{cout << "\n體積為 : " << length*width*high << endl ;}

void  cube::area2 (void)
{cout << "\n表面積為: "<< 2*(length*width+width*high+length*high) << endl;}

void main()
{
	int num1,num2,num3;
	class cube t;
	do{
		cout << "請輸入長,寬,高 : ";
		cin >> num1 >> num2 >> num3;
	}while(t.set(num1,num2,num3)==-1);
	t.area1();		t.area2();
}