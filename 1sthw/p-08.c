#include<stdio.h>
int main()
{
 int a,judge,num=0,input,i,sum=0;
 printf("Enter a number:");
 scanf("%d",&input);
 for(i=3;i<=input;i++)
 {
  judge=1;
  for(a=2;a<i;a++)
   {
    if(i%a==0)            //�P�_�O�_���]��
    judge=0;		  //���]�Ʀsfalse�ib.
   }
  if(judge==1)            //b=1�Y�����.
  {
  printf("%d ",i);	  //��ܽ��
  num++;		  //��X�Ӽ�
  sum=sum+i;		  //�[�`�M
  }
 }
 printf("\n�@ %d �ӽ��  �[�`�X = %d ",num,sum);
 system("pause");
}
