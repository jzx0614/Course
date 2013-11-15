#include<iostream>
#include<ctime>
#include<cstdio>
#include<iomanip>
using namespace std;
//________________________________�p��ɶ�__________________________________ 
class timer{
public:
       timer() { QueryPerformanceFrequency(&Frequency); }       
       inline void start() { QueryPerformanceCounter(&timerB); }  
       inline double GetTime(){
           QueryPerformanceCounter(&timerE);
           return (double)(timerE.QuadPart - timerB.QuadPart) 
                   / (double)Frequency.QuadPart *1000.0;
       }
private:
       LARGE_INTEGER timerB, timerE, Frequency;
};
//_____________________�ŧi��ƥH���H�����Ȫ�Class_________________________
class SortingDemo{
    public:
        SortingDemo(long);
        int* RandomVaule();
        void Show(int *);	
    private:
        long length;
        int *buff;      
};
//---------------------------------------------------------------------------
    SortingDemo::SortingDemo(long testsize){		//�ŧi�Ȧs��ƪ��j�p
        length=testsize;
        buff=new int[testsize];
    }
    int* SortingDemo::RandomVaule(){				//�H������
        srand(time(NULL));
        for(int i=0;i<length;i++){
                buff[i]=rand();
        }
        return buff;
    }
//___________________________�T��Sort��Class________________________________
class Sorting{
    public:
        Sorting(int n){temp=new int[n+1];};		//�غc�l�_�lclass�ܼƪ���
        
inline void setarray(int *x){list=x;};			//���ܦbclass��array��point
       
 inline void swap(int i,int j)					//Quick�Ψ쪺��ƥ洫
                {int tmp; tmp=list[i];list[i]=list[j];list[j]=tmp;}	//Quick sort
        void QuickSort(int,int); 

        void merge(int*,int*,int,int,int);
        void MergePass(int *,int *,int,int);
        void IMergeSort(int);						// Iterative Merge Sort
        
        void RMergeSort(int,int);					// Recursive Merge Sort
        void Listmerge(int,int);

    private:
        int *list;
        int *temp;
};

//---------------------------------Quick Sort-----------------------------------

    void Sorting::QuickSort(int left,int right){
      if(left<right){
         int i=left,j=right+1,pivot=list[left];
      do{
	      do i++; while (pivot>list[i]);
	      do j--; while (pivot<list[j]);     
	      if(i<j) swap(i,j);
      }while(i<j);
      swap(left,j);
      QuickSort(left,j-1);
      QuickSort(j+1,right);
      }
    }

//--------------------------Iterative Merge Sort--------------------------------
void Sorting::merge(int *initList,int *mergedList,int l,int m,int n){
      int i1=l,iResult=l,i2=m+1;
      for(;i1<=m&&i2<=n;iResult++)
            if(initList[i1]<=initList[i2])
                mergedList[iResult]=initList[i1++];
            else
                mergedList[iResult]=initList[i2++];
      if(i1>m)
            for(int t=i2;t<=n;t++)
                mergedList[iResult+t-i2]=initList[t];
      else
            for(int t=i1;t<=m;t++)
                mergedList[iResult+t-i1]=initList[t];
    }

    void Sorting::MergePass(int *initList,int *resultList,int n,int l){
       int i=1;
       for(;i<=n-2*l+1;i+=2*l)
         	merge(initList,resultList,i,i+l-1,i+2*l-1);
       if((i+l-1)<n)     	 merge(initList,resultList,i,i+l-1,n);
       else              	 for(int t=i;t<=n;t++)resultList[t]=initList[t];
    }
    void Sorting::IMergeSort(int n){
        for(int l=1;l<n;l*=2){
            MergePass(list,temp,n,l);
            l*=2;
            MergePass(temp,list,n,l);
        }
    }

//------------------------------Recursive Merge Sort----------------------------
void Sorting::RMergeSort(int left, int right){
        if(left<right){
                int mid=(left + right)/2;
                RMergeSort(left, mid);
                RMergeSort(mid+1, right);
                Listmerge(left,right);
        }
}

void Sorting::Listmerge(int left, int right)
{
        int     size=right-left+1,mid=(left+right)/2;
        int count=0;
        for(int x=left;x<=mid;x++,count++)
                temp[count]=list[x];
        for(int x=right;x>=mid+1;x--,count++)
                temp[count]=list[x];
        for(int x=0,y=size-1,put=left;x<=y;put++)
                if(temp[x]<=temp[y])
                        list[put]=temp[x++];
                else
                        list[put]=temp[y--];
}
//_______________________________�{���i�J�I_________________________________
int  main(){

    long n;
    int *list;
    
    while(1){
    
    	double sum[3]={0};
   	 cout << "\nInput size of data(Ctrl+C is stop): ";		//��J��Ƥj�p
    	cin >> n;

   	 SortingDemo hw2(n);
    	 Sorting sort(n);						//�ŧi�U��class
    	 timer sort_time;
    
    for(int i=0;i<3;i++){
      for(int j=0;j<5;j++){
        list=hw2.RandomVaule();					//���s�H������
        sort.setarray(list);
        sort_time.start();						//�_�l�ثe���ɶ�
        switch (i){
          case 0:	sort.QuickSort(0,n-1);		break;
          case 1	:sort.IMergeSort(n-1);		break;
          case 2:	sort.RMergeSort(0,n-1);	break;
        }       
        sum[i]+=sort_time.GetTime();		//���X����sort���ɶ��ìۥ[�_��
      }
        sum[i]/=5.0;						//���H���⥭��
    }
    cout<<"\n     Quick Sort   I Merge Sort   R Merge Sort\n";
    for(int i=0;i<3;i++){   
        cout<<setw(15)<<sum[i];				//displya �ɶ�
    }
    cout<<"\n\n";
    system("pause");
    }
    return 0;
}
