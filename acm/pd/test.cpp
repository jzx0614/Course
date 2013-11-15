#include <iostream> 
#include <fstream>
using namespace std;
class node{
    public:
    char aph;
    int  freq;
    node *next;
    node *left;
    node *right;
}typedef node;
int com_fun(const void *a,const void *b)
{
    node c=*(node *)a;
    node d=*(node *)b;    
    if(c.freq>d.freq){return 1;}
    else if(c.freq>d.freq) return 0;
    else    return -1;
    
}
node *head=NULL;
node *p=NULL;
node* del()
{
    node *q=head;
    head=head->next;
    return    q;
}
void insert(node *q)
{
    node *r=head,*x=head;
    if(head==NULL){ 
        head=q;
        q->next=NULL;
        return;
    }    
    while(r!=NULL)
    {
        if(r->freq>q->freq)
        {
            if(x==r){
                    q->next=head;
                    head=q;
            }      
            else{  
                    x->next=q;
                    q->next=r;            
            }    
            break;
        }
        x=r;
        r=r->next;    
    }  
    if(r==NULL){
        x->next=q;
        q->next=NULL;
    }    
}
int findtree(char c,node *p,int level){
    if(p!=NULL){
        if(p->aph==c)    
               return level;
        else{
            int x,y;
            x=findtree(c,p->left,level+1);
            if (x!=-1) return x;
            y=findtree(c,p->right,level+1);
//            return (x>y) ? x : y;
            return y;
        }    
    }
    else return -1;    
}
int main()
{
    node value[8];
    ifstream fin("pd.txt");
    char ch[]={"aeiouxys"};
    for(int i=0;i<8;i++){
        fin>>value[i].freq;
        value[i].aph=ch[i];
        value[i].left=NULL;
        value[i].right=NULL;
    }
    
    qsort(value,8,sizeof(node),com_fun);
    
    head=&value[0];
    p=head;
    p->next=NULL;
    for(int i=1;i<8;i++){
        p->next=&value[i];
        p=p->next;
        p->next=NULL;
    }    
    for(int i=0;i<7;i++){
        node *q=new node;
        q->aph=i+'0';
        q->left=del();
        q->right=del();
        q->freq=q->left->freq+q->right->freq;
        insert(q);   
    }         
    for(int i=0;i<8;i++){
        node *p=head;        
        if(i==7)
                cout<<"sp "<<findtree(ch[i],p,0)<<endl;
        else
                cout<<ch[i]<<" "<<findtree(ch[i],p,0)<<endl;
    }    
    system("PAUSE");
    return 0;    
}
