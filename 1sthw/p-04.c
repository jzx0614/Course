#include<stdio.h>
void main()
{
 int a=1,high,space,star;
 printf("請輸入三角形高度：");
 scanf("%d",&high);
 while(a<=high)
 {
    space=high;
    while(space<=high) //畫出空白◤//
     {
      if(space>a)
      printf("  ");
      space=space-1;
     }
    star=1;
    while(star<=high) //畫出星號◢//
 {
      if(star<=a)
      printf("＊");
      star=star+1;
     }
    printf("\n");
    a=a+1;
 }
}
