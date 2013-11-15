#include<stdio.h>
void main()
{
 char string[4],t;
 int i,j,c=0,max,min,ans=0;

 again:
 printf("Please input a Number:");
 scanf("%s",string);


  if(string[0]=='6'&&string[1]=='1'&&string[2]=='7'&&string[3]=='4')
   {
   printf("Error\n");
   goto again;
   }
  for(i=0;i<3;i++)
   if(string[i]==string[i+1])
    { c=c+1;}
   
  if(c==3)
   {
    printf("Error\n");
    goto again;
   }
do{
 if(ans!=0)
 {
 string[0]=ans/1000+'0';
 ans=ans%1000;
 string[1]=ans/100+'0';
 ans=ans%100;
 string[2]=ans/10+'0';
 ans=ans%10;
 string[3]=ans+'0';
 }
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
   if(string[j]<string[j+1])
   {t=string[j];string[j]=string[j+1];string[j+1]=t;}

 sscanf(string,"%d",&max);

 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
   if(string[j]>string[j+1])
   {t=string[j];string[j]=string[j+1];string[j+1]=t;}

 sscanf(string,"%d",&min);

 ans=max-min;

 printf("%d-%s=%d\n",max,string,ans);
 }while(ans!=6174);

 printf("\nThe end is 6174\n");
}