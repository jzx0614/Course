#include<iostream.h>
#include<fstream.h>
int flag=0,list[1000]={0};				//�ŧi�}�C�ΧP�_���@���ܼ�
void swap(int i,int j)			
{
 int tmp;
 tmp=list[i];                    
 list[i]=list[j];							// ��ƥ洫��m
 list[j]=tmp;
}

void quick(int left,int right)	// QuickSort
{											
 int i,j,pivot;								//pivot ���@�ӰѦҼ�,�Ҩ��}�C�Ĥ@�Ӽ�
	
 if(left<right)						
 {
  i=left;j=right;pivot=list[left];
  do{
	do i++; while (pivot>list[i]);			//���pivot�p���Ʋ���}�C����
	do j--; while (pivot<list[j]);			//���pivot�j���Ʋ���}�C�k��

	if(i<j) swap(i,j);

  }while(i<j);

  swap(left,j);

  quick(left,j);						//������b�~�򻼦^
  quick(i,right);
 }
}
void b(int x,int left,int right,int y)		//binary Search
{
	if(left<right)
	{	
		int i=(left+right)/2;				//���}�C��m������
		if(x==list[i])						//���󬰵���
		{
			cout<<"("<<y<<","<<list[i]<<") \n";
			flag=1;							//����쵪�ױNflag�אּtrue 
		}
		else if(x>list[i])					//��x�j���᭱�@�b�A�j�M
			b(x,i+1,right,y);
		else if(x<list[i])					//��x�p���e���@�b�A�j�M
			b(x,left,i-1,y);
		
	}
}
int main()
{
	
	int z,N,temp;					//	z���ҭn���M�AN�����X�����X�Ӽ�		
	ifstream fin("number.txt");		//	�}�_number�ɮ�	
	fin >> z >> N ;					//  �q�ɮ׶}�_�Ȧs�iz N ����ܼ� 
				
	for(int i=0;i<N;i++)
		fin >> list[i];				//  �N�l���X���Ƥ@�@�s�ilist�}�C		
	
	quick(0,N);				//  �ֳt�ƧǪk
					
	for(i=0;list[i]*2<z;i++){		//  list[i]*2 <z �O�������X����
		temp=z-list[i];				//	�N�M��h�@�}�C���䤤�@�Ӽ�	
		b(temp,0,N,list[i]);		//	binary Search
	}

	if(!flag) 
		cout<<"Error"<<endl;		// �䤣��ŦX����ӼơA�L�X���~�T��	
	fin.close();					// ����
	return 0;
}
