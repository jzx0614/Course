#include<stdio.h>
#include<stdlib.h>
                                                                                
void main()
{
 int guess=0,ans,c=0;
 randomize();
 ans=rand()%1000+1;
                                                                                
 printf("\n亂數=%d\n",ans);
 while(ans!=guess)
 {
  printf("請輸入一個數值:");
  scanf("%d",&guess);
  if(guess>ans)
    printf("Error 小一點\n");
  else
   if(guess<ans)
    printf("Error 大一點\n");
  c++;
 }
