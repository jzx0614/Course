#include <iostream>
#include <fstream>
using namespace std;
class Task
{
    public:
        int money;
        int deadline;
};    
void swap (class Task *p,class Task *q)
{
    class Task *t;
    memcpy(t,p,sizeof(class Task));
    memcpy(p,q,sizeof(class Task));
    memcpy(q,t,sizeof(class Task));
}
int compare(class Task *p,class Task *q)
{
    if(p->money==q->money)
        return    p->deadline-q->deadline;
    return p->money-q->money;
}

void b_sort(class Task list[],int Len)
{
    for(int i=0;i<(Len-1);i++)
    for(int j=0;j<(Len-1);j++)
    	if(compare(&list[j],&list[j+1])<0)  
            swap(list[j],list[j+1]);
}
int main(void)
{
    char file[10];
    int num,maxdeadline=0,total=0,list[500]={0};
    cout<<"Input Filename : ";
    cin>>file;
    
    ifstream fin (file);
    fin>>num;
    
    class Task task[num];
    
    for(int i=0;i<num;i++)
        fin>>task[i].money;
    for(int i=0;i<num;i++)
    {	
        fin>>task[i].deadline;
        if(maxdeadline<task[i].deadline)
    		maxdeadline=task[i].deadline;
    }
    fin.close();
	 	
    b_sort(task,num);
		
    for(int i=0;i<num;i++)
        for(int j=task[i].deadline-1;j>=0;j--)
	    	if(list[j]==0){
				list[j]=i+1;
 				total+=task[i].money;			 				
 				break;
 			}
		
	cout<<"\ntime   value   deadline\n";
    for(int i=0;i<maxdeadline;i++)
    	if(list[i]==0)
    		cout<<"  "<<i+1<<"\t-\t-\n";
    	else
        	cout<<"  "<<i+1<<"\t"<<task[list[i]-1].money<<"\t"<<task[list[i]-1].deadline<<endl;    
    cout<<"\ntotal = "<<total<<endl;
  
    system("PAUSE");
}
