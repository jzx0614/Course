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
	Two3(int max,Two3Node *init=0):MAXKEY(max),root(init){};   //constructor

	Two3Node* Search(int,int);  	                               // Search
	
	    int compare(Two3Node *,int x);

    bool Insert(int);                                          // Insert
    
        Two3Node* FindNode(int x,int select);
        void NewRoot(int x,Two3Node *a);
        void InsertionError(){cout<<"Insertion Error\n";};
        void PutIn(Two3Node *p,int x,Two3Node *a);
        int Split(Two3Node* p,int ,Two3Node *olda,Two3Node *a);
		void show(Two3Node *p,int);
		Two3Node* getroot(){return root;}
	
	bool Delete(int a);                                        // Delete
		void DeletionError(){cout<<"Deletion Error\n";}
		void rotation(Two3Node *p,Two3Node *q,Two3Node *r,int);
		void combine(Two3Node *p,Two3Node *q,Two3Node *r,int);

private:
	Two3Node *root;
	int MAXKEY;
};
void Two3::show(Two3Node *p,int c){
	if(p!=0){
		cout<<p->dataL<<" "<<p->dataR<<"  \n";
		if(p->LeftChild!=0){
			cout<<c<<"Left: ";
			show(p->LeftChild,c+1);
			}
		if(p->MiddleChild!=0){
			cout<<c<<"Middle: ";
			show(p->MiddleChild,c+1);
		}
			
		if(p->dataR!=MAXKEY&&p->RightChild!=0){
			cout<<c<<"Right: ";
			show(p->RightChild,c+1);
		}	
		if(p->LeftChild||p->MiddleChild||(p->dataR!=MAXKEY&&p->RightChild))cout<<"\n";
	}
}
/*****************************************Search************************************************/
  Two3Node* Two3::Search(int x,int select){
	  Two3Node *q=root;
      for(Two3Node *p =root;p;)
            switch(compare(p,x)){
				  q=p;
                  case 1:p=p->LeftChild;     break;
                  case 2:p=p->MiddleChild;   break;
                  case 3:p=p->RightChild;    break;
                  case 4:     return (select==0) ? p : q;               //x is one of the keys in p
            }
	  return 0;
  }

  int Two3::compare(Two3Node *p,int x){
    if (x<(p->dataL))                        return 1;
    else if ((p->dataL)<x && x <(p->dataR) )   return 2;
    else if ((p->dataR) < x)                 return 3;
    else                                   return 4;
  } 
/*****************************************Insert************************************************/
  bool Two3::Insert(int y){
    Two3Node *p;
    int x=y;
    if(x>=MAXKEY)            return false;            //invalid key
    if(!root){NewRoot(x,0);  return true; }           //empty 2-3 tree
    if(!(p=FindNode(x,0))){InsertionError();return false;}//key already in 2-3 tree
    for(Two3Node *a=0;;)
        if(p->dataR==MAXKEY){                         // p is a 2 node
           PutIn(p,x,a);
           return true;
        }
        else {                                        // p is a  3 node
           Two3Node *olda=a;
           a=new Two3Node;
           x=Split(p,x,olda,a);
           if(root==p){                               //root has been split
              NewRoot(x,a);
              return true;
           }
           else p=FindNode(x,1);
        }
	return 0;
  }                                    
 
  Two3Node* Two3::FindNode(int x,int select){
     Two3Node *q=0,*r=0;
	 for(Two3Node *p=root;p;){
		  r=q;q=p;	  
		  switch(compare(p,x)){
               case 1:p=p->LeftChild;     break;
               case 2:p=p->MiddleChild;   break;
               case 3:p=p->RightChild;    break;
               case 4:    return 0;               //x is one of the keys in p
            }
	 }
	 return (select==0) ? q : r;
	 
  }
  void Two3::NewRoot(int x,Two3Node *a){
	Two3Node *p=new Two3Node;
	p->dataL=x;
	p->dataR=MAXKEY;
	p->LeftChild=root;
	p->MiddleChild=a;

	root=p;
  }
  void Two3::PutIn(Two3Node *p,int x,Two3Node *a){
	  if(p->dataL<x){
		p->dataR=x;
		p->RightChild=a;
	  }
	  else{
		p->dataR=p->dataL;
		p->dataL=x;
		p->RightChild=p->MiddleChild;
		p->MiddleChild=a;
      }

  }
  int Two3::Split(Two3Node* p,int x,Two3Node *olda,Two3Node *a){
	  int mid;
	  switch(compare(p,x)){
	    case 1: 
			mid=p->dataL;

			a->dataL=p->dataR; 
			a->dataR=MAXKEY;
			a->LeftChild=p->MiddleChild;
			a->MiddleChild=p->RightChild;

			p->dataL=x;
			p->dataR=MAXKEY;
			p->MiddleChild=p->LeftChild;
			p->LeftChild=olda;

			break;
		case 2: 
			mid =x;
			a->dataL=p->dataR;
			a->dataR=MAXKEY;
			a->MiddleChild=p->RightChild;
			a->LeftChild=olda;

			p->dataR=MAXKEY;

			break;
		case 3: 
			mid=p->dataR;
			
			a->dataL=x;
			a->dataR=MAXKEY;
			a->MiddleChild=olda;
			a->LeftChild=p->RightChild;

			p->dataR=MAXKEY;

			break;
	  }
	  return mid;
  }
/*****************************************Delete************************************************/
  bool Two3::Delete(int a){
	Two3Node *p=Search(a,0),*r=Search(a,1);
	if(p==0){DeletionError(); return false;}      // Deletion no value
	if(p->LeftChild!=0){                             // It is not Leaf
		if(a==p->dataL){                          //dataL
			if(p->LeftChild->dataL!=MAXKEY){
				p->dataL=p->LeftChild->dataL;
				Delete(p->LeftChild->dataL);
            }
			else{
				p->dataL=p->LeftChild->dataR;
			    Delete(p->LeftChild->dataR);
            }
		}
		else if(a==p->dataR){                   //dataR			
			p->dataR=p->RightChild->dataL;
			Delete(p->RightChild->dataL);
        }
	}
	else{                                      //It's leaf
		if(p->dataR==MAXKEY){                  //p is 2 node
			p->dataL=MAXKEY;
			
			if(r==0){return true;}
			if(p==r->LeftChild){
				if(r->MiddleChild->dataR!=MAXKEY)
					rotation(p,r->MiddleChild,r,1);	
				else{
					if(r->dataR==MAXKEY)
						combine(p,r->MiddleChild,r,1);
					else
						combine(p,r->MiddleChild,r,2);
				}
				return true;
			}
			else if(p==r->MiddleChild){
				if(r->dataR==MAXKEY)
					if(r->LeftChild->dataR!=MAXKEY)
						rotation(p,r->LeftChild,r,2);
					else
							r->MiddleChild=0;
					
				else{
					if(r->RightChild->dataR!=MAXKEY)
						rotation(p,r->LeftChild,r,4);
					else if(r->LeftChild->dataR!=MAXKEY)
						rotation(p,r->LeftChild,r,2);
					else combine(p,r->MiddleChild,r,4);

				}
				return true;
			}
			else if(p==r->RightChild){
				if(r->MiddleChild->dataR!=MAXKEY)
					rotation(p,r->RightChild,r,3);
				else 
					combine(p,r->MiddleChild,r,3);
				return true;
			}
		}
		else{                                  //p is 3 node
			if(a==p->dataL){
				p->dataL=p->dataR;
				p->dataR=MAXKEY;
				return true;
			}
			else{
				p->dataR=MAXKEY;
				return true;
			}
        }
    }
  }

  void Two3::rotation(Two3Node *p,Two3Node *q,Two3Node *r,int x){
	  switch(x){
		case 1:
			p->dataL=r->dataL;
			p->MiddleChild=q->LeftChild;
			r->dataL=q->dataL;

			q->dataL=q->dataR;
			q->LeftChild =q->MiddleChild;
			q->MiddleChild=q->RightChild;
			q->dataR=MAXKEY;
			q->RightChild=0;

		break;
		case 2:
			p->MiddleChild=p->LeftChild;
			p->dataL=r->dataL;
			p->LeftChild=q->RightChild;
			r->dataL=q->dataR;
			q->dataR=MAXKEY;
		break;
		case 3:
			p->MiddleChild=p->LeftChild;
			p->dataL=r->dataR;
			p->LeftChild=q->RightChild;
			r->dataR=q->dataR;
			q->dataR=MAXKEY;
		break;
		case 4:
			p->dataL=r->dataL;
			p->MiddleChild=q->LeftChild;
			r->dataR=q->dataL;
			q->LeftChild=q->MiddleChild;
			q->dataL=q->dataR;
			q->MiddleChild=q->RightChild;
			q->dataR=MAXKEY;
			q->RightChild=0;
		break;
			
	  }
  }

  void Two3::combine(Two3Node *p,Two3Node *q,Two3Node *r,int select){
	  switch(select){
	   case 1:
		   	if(r==root){root=p;}
			else{
				if(Search(r->dataL,1)->LeftChild==r){Search(r->dataL,1)->LeftChild=p;}
				else if(Search(r->dataL,1)->MiddleChild==r){Search(r->dataL,1)->MiddleChild=p;}
				else if(Search(r->dataL,1)->RightChild==r){Search(r->dataL,1)->RightChild=p;}
			}
			p->dataL=r->dataL;
			p->MiddleChild=q->LeftChild;
			p->dataR=q->dataL;
			p->RightChild=q->MiddleChild;
			r->MiddleChild=0;
			r->dataL=MAXKEY;

	   break;
	   case 2:
			p->dataL=r->dataL;
			p->MiddleChild=q->LeftChild;
			p->dataR=q->dataL;
			p->RightChild=q->MiddleChild;
			r->dataL=r->dataR;
			r->MiddleChild=r->RightChild;
			r->dataR=MAXKEY;
			r->RightChild=0;
   	   break;
	   case 3:
		   q->dataR=r->dataR;
		   q->RightChild=0;
		   r->dataR=MAXKEY;
		   r->RightChild=0;
	   break;
	   case 4:
		   p->dataL=r->dataL;
		   p->dataR=q->dataL;
		   r->dataR=MAXKEY;
		   p->LeftChild=0;
		   p->MiddleChild=q->LeftChild;
		   p->RightChild=q->MiddleChild;
		break;
	  }
  }
int main ()
{
    class Two3 treeDemo(999) ;
	int x,select;
	do{
	cout<< "(1)Insertion \n(2)Search \n(3)Deletion \nselect : ";
	cin>>select;
	switch(select){
		case 1:
			cin >> x;
			treeDemo.Insert(x);
			cout<<endl;	
		break;

		case 2:
			cout<<"Search: ";
			cin >> x;
			if(treeDemo.Search(x,0)) cout<<"true\n";
		break;

		case 3:
			cout<<"Delete: ";
			cin >> x;
			treeDemo.Delete(x);
		break;
	}treeDemo.show(treeDemo.getroot(),1);
	}while(select!=0);
	return 0;
}

