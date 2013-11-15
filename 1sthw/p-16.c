#include<stdio.h>
void main()
{
 char string[20],name[6][6]={' '};
 int math,engl,chin,sum,i,j,k,c;
 float ave,a[10][6],hsum,lsum,t;

 for(i=0;i<=5;i++)
 {
  scanf("%s",string);
  for(j=0;j<20;j++)
   {
    if(string[j]==',')
     {
     string[j]=' ';
     }
   }

  sscanf(string,"%s%d%d%d",name[i],&chin,&engl,&math);

  sum=math+engl+chin;
  ave=sum/3.0;

  a[i][0]=chin;
  a[i][1]=engl;
  a[i][2]=math;
  a[i][3]=sum;
  a[i][4]=ave;
  a[i][5]=1.0;
  a[6][i]=0.0;

 }
 for(i=0;i<6;i++)
  for(j=0;j<6;j++)
   if(a[i][3]<a[j][3]&&i!=j)
    a[i][5]++;

 printf("       國文      英文    數學   總 分    平均  名 次\n");

 for(i=0;i<=5;i++)
 {
  for(j=0;j<=5;j++)
  {
   printf("%c",name[i][j]);
  }

  for(j=0;j<=5;j++)
  {
   if(j!=4)
    printf(" %.f\t",a[i][j]);
   else
    printf(" %.1f\t",a[i][j]);
  }
  printf("\n");
 }

 for(k=0;k<=2;k++)
  for(i=6;i>0;i--)
   for(j=0;j<=4;j++)
   {
    if(a[j][k]>a[j+1][k])
    {
     t=a[j][k];
     a[j][k]=a[j+1][k];
     a[j+1][k]=t;
    }
   }

 for(i=0;i<6;i++)
 {lsum=0.0;
  hsum=0.0;
  for(j=0;j<6;j++)
   {
    a[6][i]+=a[j][i];
    if(j<=2)
     lsum+=a[j][i];
    else if(j>=3)
     hsum+=a[j][i];
   }
    a[7][i]=a[6][i]/6.0;
    a[8][i]=hsum/3.0;
    a[9][i]=lsum/3.0;

 }
 sprintf(name[6],"  總分");
 sprintf(name[7],"  平均");
 sprintf(name[8],"  高標");
 sprintf(name[9],"  低標");
 for(i=6;i<=9;i++)
 {
  for(j=0;j<6;j++)
    printf("%c",name[i][j]);
  for(j=0;j<3;j++)
   {
   if(i!=6)
    printf(" %.1f\t",a[i][j]);
   else
    printf(" %.f\t",a[i][j]);
   }
    printf("\n");
 }
}
