#include<stdio.h>
void main()
{
 char a[10]={0};
 int i,j=8,sum;
 printf("\n\n請輸入身份證號碼：");
 scanf("%s",&a);
   if(a[0]<='H'||a[0]=='W')
    a[0]=a[0]-'A'+10;
   else if('J'<=a[0]&&a[0]<='N')
    a[0]=a[0]-'A'+9;
   else if('P'<=a[0]&&a[0]<='V'||a[0]=='Z')
    a[0]=a[0]-'A'+8;
   else if('X'<=a[0]&&a[0]<='Y')
    a[0]=a[0]-'A'+7;
   else if(a[0]=='I')
    a[0]=a[0]-'A'+26;
   else  if(a[0]=='O')
    a[0]=a[0]-'A'+21;
   sum=a[0]/10+a[0]%10*9;
 for(i=1;i<=9;i++)
  {
   if(i==9)
   j++;
   a[i]=(a[i]-'0')*j--;
   sum=sum+a[i];
  }
 if(sum%10==0)
  {
   printf("\n此身分證是有效的\n");
   if (a[1]==8)
    printf("這是男生的身份證 ,");
   else if (a[1]==16)
    printf("這是女生的身份證 ,");
   switch(a[0])
    {
     case 10:
	printf("所在地為台北市");break;
     case 11:
	printf("所在地為台中市");break;
     case 12:
	printf("所在地為基隆市");break;
     case 13:
	printf("所在地為台南市");break;
     case 14:
	printf("所在地為高雄市");break;
     case 15:
	printf("所在地為台北縣");break;
     case 16:
	printf("所在地為宜蘭縣");break;
     case 17:
	printf("所在地為桃園縣");break;
     case 18:
	printf("所在地為新竹縣");break;
     case 19:
	printf("所在地為苗栗縣");break;
     case 20:
	printf("所在地為台中縣");break;
     case 21:
	printf("所在地為南投縣");break;
     case 22:
	printf("所在地為彰化縣");break;
     case 23:
	printf("所在地為雲林縣");break;
     case 24:
	printf("所在地為嘉義縣");break;
     case 25:
	printf("所在地為台南縣");break;
     case 26:
	printf("所在地為高雄縣");break;
     case 27:
	printf("所在地為屏東縣");break;
     case 28:
	printf("所在地為花蓮縣");break;
     case 29:
	printf("所在地為台東縣");break;
     case 30:
	printf("所在地為澎湖縣");break;
     case 31:
	printf("所在地為陽明山");break;
     case 32:
	printf("所在地為金門縣");break;
     case 33:
	printf("所在地為連江縣");break;
     case 34:
	printf("所在地為嘉義市");break;
     case 35:
	printf("所在地為新竹市");break;
    }
  }
 else
   printf("此身分證是無效的\n");

}