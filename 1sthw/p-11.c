#include<stdio.h>
#include<stdlib.h>
                                                                                
void main()
{
 int guess=0,ans,c=0;
 randomize();
 ans=rand()%1000+1;
                                                                                
 printf("\n�ü�=%d\n",ans);
 while(ans!=guess)
 {
  printf("�п�J�@�Ӽƭ�:");
  scanf("%d",&guess);
  if(guess>ans)
    printf("Error �p�@�I\n");
  else
   if(guess<ans)
    printf("Error �j�@�I\n");
  c++;
 }
