#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
 {
  time_t t;
  int i,j,c=0,A,B;
  char input[4],a[4];
  srand(time(&t));

  Again:
   for(i=0;i<=3;i++)
    a[i]=rand()%10;
   for(i=0;i<=3;i++)
    for(j=0;j<=3;j++)
     if(a[i]==a[j]&&i!=j)
     goto Again;
  for(i=0;i<=3;i++)
   printf("%d",a[i]);
  do{
   printf("\n請輸入第%d組數字:",c+1);
   scanf("%s",input);
   A=0;
   B=0;
   c=c+1;
   for(i=0;i<=3;i++)
    {
     input[i]=input[i]-'0';
     if(a[i]==input[i])
     A++;
    }
    for(i=0;i<=3;i++)
     {
     for(j=0;j<=3;j++)
      if(a[i]==input[j]&&i!=j)
       B++;
     }
   printf("你猜測的結果:%dA%dB\n",A,B);
  }while(A!=4);

  printf("\n標準答案為:");
  for(i=0;i<=3;i++)
  printf("%d",a[i]);
  printf(" 你共猜了%d次",c);
  delay(4000);

 }