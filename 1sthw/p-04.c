#include<stdio.h>
void main()
{
 int a=1,high,space,star;
 printf("�п�J�T���ΰ��סG");
 scanf("%d",&high);
 while(a<=high)
 {
    space=high;
    while(space<=high) //�e�X�ťբ�//
     {
      if(space>a)
      printf("  ");
      space=space-1;
     }
    star=1;
    while(star<=high) //�e�X�P����//
 {
      if(star<=a)
      printf("��");
      star=star+1;
     }
    printf("\n");
    a=a+1;
 }
}
