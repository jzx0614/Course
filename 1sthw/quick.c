#include<stdio.h>
#include<conio.h>

void swap(int list[],int i,int j)
{
 int tmp;
 tmp=list[i];                      /*兩數交換*/
 list[i]=list[j];
 list[j]=tmp;
}

void quick(int list[],int left,int right)
{
 int i,j,pivot;
 if(left<right)
 {
  i=left;j=right+1;pivot=list[left];
  do{
	do i++; while (pivot>list[i]);
	do j--; while (pivot<list[j]);     /*快速排序法*/

	if(i<j) swap(list,i,j);

  }while(i<j);

  swap(list,left,j);

  quick(list,left,j-1);
  quick(list,i,right);
 }
}


int main()
{
 int a[16]={10,3,5,8,7,1,2,9,11,12,27,7,2,9,4,85},i;

 quick(a,0,15);
 for(i=0;i<16;i++)
  printf("%d ",a[i]);
 system("PAUSE");
 return 0;
}
