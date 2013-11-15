#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#include<stdio.h>
#define Maxword 500
class library
{
    public:
        char e_word[10];
        char c_word[20];
        int prob; 
};
class TreeNode
{
    public:
        int data; 
        class TreeNode *left,*right;
};
int compare(const void *a, const void *b)
{
    class library p=*(class library *)a;
    class library q=*(class library *)b;
    return(strcmp(p.e_word,q.e_word));
}

class words{
    public:
        words();
        void obst();
        class TreeNode *  BuildTree(int,int);
        void search(char *);
        void showtable();
        void showword();
    private:    
        int N;
        int root[Maxword][Maxword];
        int cost[Maxword][Maxword];
        class library lib[Maxword];
        class TreeNode *obstree;
};
words::words()
{
    char filename[10];
    cout<<"Input filename : ";
    cin >> filename;
    ifstream fin (filename);
    for(N=0;!fin.eof();N++)
    {
        fin>>lib[N].e_word>>lib[N].c_word>>lib[N].prob;
    }
    fin.close();
 
    memset(root,(0),sizeof(root));
    memset(cost,(0),sizeof(cost));
    
    qsort(lib, N, sizeof(class library), compare);
  
}
void words::obst()
{
    for(int i=0;i<N;i++){
        root[i][i]=i;
        cost[i][i]=lib[i].prob;
    }    
    for(int m=1;m<N;m++)
        for(int i=0;i<N-m;i++)
        {
            int j=i+m,sum=0;
         
            for(int k = i; k <=j; k++)
                sum+=lib[k].prob;

            int minicost=9999;
            for(int k = i; k <=j; k++)
                if(minicost>=cost[i][k-1]+cost[k+1][j]){
                    minicost=cost[i][k-1]+cost[k+1][j];
                    root[i][j]=k;
                } 
            cost[i][j]=sum+minicost;
        } 
    showtable();
    obstree= BuildTree(0,N-1);
}
class TreeNode * words::BuildTree(int i,int j)
{
    class TreeNode *p=new (class TreeNode);
    if(i>j){
        p=NULL;
    }
    else{    
        p->data=root[i][j];
        p->left=BuildTree(i,root[i][j]-1);
        p->right=BuildTree(root[i][j]+1,j);
    }    
    return p;
}
void words::search(char *buf)
{
    int t;
    class TreeNode *p=obstree;
    cout<<"\nSearch . . ";
    while(p!=NULL){
            cout<<lib[p->data].e_word<<" . . ";
        if((t=strcmp(buf,lib[p->data].e_word))==0){
            cout<<"\n\n"<<lib[p->data].e_word<<"\t"<<lib[p->data].c_word<<endl;
            break;
        }
        else if(t>0)
            p=p->right;
        else if(t<0)
            p=p->left;
    }
    if(p==NULL){
        cout<<"\nThis word isn't exist."<<endl;
    }    
}
void words::showword()
{
    for(int i=0;i<N;i++)
        cout<<lib[i].e_word<<"\t"<<lib[i].c_word<<"\t"<<lib[i].prob<<endl;      
}
void words::showtable()
{       
    cout<<"\nroot \n";
    for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
        if(i<=j)
            printf("%3d ",root[i][j]);
         else
            cout<<"    ";
    cout<<endl;
    }    
    cout<<"cost \n";
    for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
        if(i<=j)    
            printf("%3d ",cost[i][j]);
         else
            cout<<"    ";        
    cout<<endl;
    }       
}

int main(void)
{
    char buff[10],msg;
    class words hw4; 
    hw4.obst();
    do{
        cout<<"\n(1)Search English Word. \n(2)Show DP table\n(0)Exit.\n\nSelect a number: ";
        cin>>msg;
        system("cls");
        hw4.showword();
        switch(msg)
        {
            case '1':
                cout<<"\nInput English word: ";
                cin >>buff;
                hw4.search(buff);
                break;
            case '2':
                hw4.showtable();
                break;
            default: break; 
        }
    }while(msg!='0');    
}
