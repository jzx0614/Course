#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define Prime 97
class Spell;
class ListNode{
    friend class Spell;
    private:
        char ident[40];
        ListNode *link;  
};
typedef ListNode* ListPtr;

class Spell{
    public:
        Spell();
        void ReadFile(char file[]);
        void WriteFile(char word[]);
        void ReadWord(char file[]);
        int  Hfunc(char word[]);
        void Insert(char word[],int attr);
        bool IsIn(char buff[]);
        void Findlcs(char word[]);
        int  max(int a, int b);
        int  lcs(char n[], char m[]);
    private:
        ListPtr *ht;      
};

Spell::Spell()
{
    ht=new ListPtr[Prime];
    for(int i=0;i<Prime;i++){ht[i]=NULL;}
    
}
void Spell::ReadFile(char filename[]){
    char buff[40];
    ifstream fin (filename);
    while(!fin.eof()){
        fin>>buff;  
        if(!IsIn(buff)){
          Findlcs(buff);
        }
    }
}
void Spell::WriteFile(char word[]){
    ofstream fout ("Output.txt", ios::app);
    fout << word <<endl;
    
}
void Spell::ReadWord(char file[])
{   char buff[40];
    ifstream fin (file);
    while(!fin.eof())
    {
        fin>>buff;
        Insert(buff,Hfunc(buff));
    }
    
    fin.close();
}
void Spell::Insert(char word[],int attr){
    ListPtr l= ht[attr];
    if(ht[attr]==NULL){
        ht[attr]=new ListNode;
        strcpy(ht[attr]->ident,word);
        ht[attr]->link=NULL;
    }
    else{
        ListPtr l=ht[attr];
        while(l->link!=NULL){l=l->link;}
        l->link=new ListNode;
        l=l->link;
        strcpy(l->ident,word);
        l->link=NULL;  
    }    
}
int Spell::Hfunc(char tmp[]){
    long sum=0;
    for(int i=0;i<strlen(tmp);i++){sum+=tmp[i];}    
    return (sum%Prime);
    
}
bool Spell::IsIn(char buff[]){
  
    int j=Hfunc(buff);
    for(ListPtr l=ht[j];l!=NULL;l=l->link){
        if(strcmp(l->ident,buff)==0)    
                return true;
    }
    return false;
}
void Spell::Findlcs(char word[]){

    int j=Hfunc(word);
    char string2[]={"的建議字為：\n"},string1[]={"\n\n"};
        strcat(string1,word);
    strcat(string1,string2);
    WriteFile(string1);
    for(int i=j-5;i<j+5;i++)
      for(ListPtr l=ht[i];l!=NULL;l=l->link)
          if(strlen(l->ident)-strlen(word)==0)
             if(lcs(l->ident,word)==strlen(word)-2)
                  WriteFile(l->ident);

          
}
int Spell::max(int a, int b)
{
    if (a >= b) return a;
    else return b;
}

int Spell::lcs(char n[], char m[]) 
{
    int lcstable[40][40] = {{0}, {0}};
    for (int i=1;i<=strlen(n);i++)
    {
        for (int j=1;j<=strlen(m);j++)
        {
            if (n[i-1] == m[j-1])
                lcstable[i][j] = lcstable[i-1][j-1] + 1;
            else
                lcstable[i][j] = max(lcstable[i-1][j],lcstable[i][j-1]);
        }
    }
    return lcstable[strlen(n)][strlen(m)];
}
int main () {
    char file[]={"words.txt"};
    char filename[]={"Input.txt"};
    Spell demo;
    demo.ReadWord(file);
    demo.ReadFile(filename);
    system("pause");
    return 0;
}
