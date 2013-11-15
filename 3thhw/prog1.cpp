#include<iostream.h>
#include<fstream.h>
int flag=0,list[1000]={0};				//宣告陣列及判斷的一個變數
void swap(int i,int j)			
{
 int tmp;
 tmp=list[i];                    
 list[i]=list[j];							// 兩數交換位置
 list[j]=tmp;
}

void quick(int left,int right)	// QuickSort
{											
 int i,j,pivot;								//pivot 為一個參考數,皆取陣列第一個數
	
 if(left<right)						
 {
  i=left;j=right;pivot=list[left];
  do{
	do i++; while (pivot>list[i]);			//把比pivot小的數移到陣列左邊
	do j--; while (pivot<list[j]);			//把比pivot大的數移到陣列右邊

	if(i<j) swap(i,j);

  }while(i<j);

  swap(left,j);

  quick(left,j);						//分成兩半繼續遞回
  quick(i,right);
 }
}
void b(int x,int left,int right,int y)		//binary Search
{
	if(left<right)
	{	
		int i=(left+right)/2;				//取陣列位置的中間
		if(x==list[i])						//等於為答案
		{
			cout<<"("<<y<<","<<list[i]<<") \n";
			flag=1;							//有找到答案將flag改為true 
		}
		else if(x>list[i])					//比x大取後面一半再搜尋
			b(x,i+1,right,y);
		else if(x<list[i])					//比x小取前面一半再搜尋
			b(x,left,i-1,y);
		
	}
}
int main()
{
	
	int z,N,temp;					//	z為所要的和，N為集合中有幾個數		
	ifstream fin("number.txt");		//	開起number檔案	
	fin >> z >> N ;					//  從檔案開起值存進z N 兩個變數 
				
	for(int i=0;i<N;i++)
		fin >> list[i];				//  將子集合的數一一存進list陣列		
	
	quick(0,N);				//  快速排序法
					
	for(i=0;list[i]*2<z;i++){		//  list[i]*2 <z 是不讓集合重覆
		temp=z-list[i];				//	將和減去一陣列中其中一個數	
		b(temp,0,N,list[i]);		//	binary Search
	}

	if(!flag) 
		cout<<"Error"<<endl;		// 找不到符合的兩個數，印出錯誤訊息	
	fin.close();					// 關檔
	return 0;
}
