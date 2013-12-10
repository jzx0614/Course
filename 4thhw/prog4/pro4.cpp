#include<iostream> 
using namespace std;

class Two3;

class Two3Node{
friend class Two3;
private:
	int dataL,dataR;
	Two3Node *LeftChild,*MiddleChild,*RightChild;
};
class Two3{
public:
	//Two3(int max,Two3Node *init=0):MAXKEY(max),root(init){};		//constructor
	Boolean Insert(int);
	Boolean Delete(int);
	Two3Node* Search(int );
private:
	Two3Node *root;
	int MAXKEY;
};
int main ()
{
	class Two3 23treeDemo=new Two3 ();
	return 0;
}