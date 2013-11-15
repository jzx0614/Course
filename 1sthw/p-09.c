#include<stdio.h>

int main()
{
 int input,i,j,q,r,judge[2];
 printf("Enter a number:");
 scanf("%d",&input);
 for(i=2;i<input;i++)
 {
  judge[0]=1;
  for(j=2;j<i;j++)
  {
   if(i%j==0)
    {judge[0]=0;break;}
  }
   if(judge[0]==1)
    {
     if(input%i==0&&i>input/i)
      {q=input/i;
       judge[1]=1;
       for(r=2;r<q;r++)
	if(q%r==0)
	 {judge[1]=0;break;}
	 if(judge[1]==1)
	   printf("%d=%d*%d\n",input,i,q);
	  else
	   printf("Error a number\n");
      }
    }
 }
system("pause");

}
