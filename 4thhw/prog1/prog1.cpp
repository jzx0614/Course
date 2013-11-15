#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;

class Graph {
public:
    Graph(char file[]);                    // initial graph length
    int AllLengths();                      // all -pairs shortest paths
    void ShowAllpair();                    // show all pair matrix
    bool Isdirection(int,int);             // judge i j is dircetion
    void SearchPath(int,int,int);          // Search a to b of shortest path
        
private:
    int length[20][20];       //the adjacency matrix of a graph
    int A[20][20];            //all-pairs shortest of matrix
    int n;                    //n Vertics
    int path[3][8000];        //save all-pairs change step
};

Graph::Graph(char file[]){      
     
    char buff[100];n=1;             
    ifstream fin (file);                //open file 

    fin.getline(buff,100);              //get file first line
    length[0][0]=0;                      
    for(int i=0;i<strlen(buff);i++)
        if (buff[i]==' '){              //use 'space' to compute Vertics 
        length[0][n]=atoi(buff+i+1);    //store first line from buff to length[]
        n++;
        }
    
    while(!fin.eof()){                  //other use open file to length[]
        for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
                fin>>length[i][j];
    }
    fin.close();
    for(int i=0;i<n;i++)                //copy length[][] to A[][]
        for(int j=0;j<n;j++)
                A[i][j]=length[i][j];
    cout<<"A(-1)\n";
    ShowAllpair();                      //show A (-1)
}

int Graph::AllLengths(){
    int x=0;
    for(int k=0;k<n;k++){         //for a path with highest vertex index k
    for(int i=0;i<n;i++){    //for all possible pairs of vertices
    for(int j=0;j<n;j++){    
        if((A[i][k]+A[k][j])<A[i][j]){
           A[i][j]=A[i][k]+A[k][j];
           path[0][x]=i;path[1][x]=j;path[2][x++]=k;  //store change path
        }
    }}
    cout<<"A("<<k<<")"<<endl;
    ShowAllpair();
    }
           
}
void Graph::ShowAllpair(){                     //Display A[][]
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<setw(4)<<A[i][j];}
        cout<<endl;
     }cout<<endl;
}
bool Graph::Isdirection(int i,int j){
    return (A[i][j]!=99) ? true : false;
}
void Graph::SearchPath(int i,int j,int k){    //use Recursive Search path[][]
    if(k==-1){                                 //if no change print i j.
        cout<<"("<< i <<","<< j<<") ";}       
    else if(i==path[0][k]&&j==path[1][k]){    //if it's in path[][]
              SearchPath(i,path[2][k],k-1);   //Recursive i to k path
              SearchPath(path[2][k],j,k-1);   //Recursive k to j path
        }          
    else{
        SearchPath(i,j,k-1);}                 //continue next path[][]
    
}
int main(){
    char file[20];        
    int i,j,k;
    cout << "Input Filename: ";               //type filename 
    cin  >> file; 
    
    Graph prog1(file);                        
    k=prog1.AllLengths();                    //all-pairs shortest paths
            
    while(1){                                //input i to j
    cout << "choose i to j path (i j) : ";
    cin  >> i >> j;
    
    if(prog1.Isdirection(i,j))              
        prog1.SearchPath(i,j,k-1);          //Search i to j path and display path
    else
        cout<<i<<" to "<<j<<" is not path.";
    cout<<endl;
    }
    return 0;
}

