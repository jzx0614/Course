#include<stdio.h>
void main()
{
 char a[10]={0};
 int i,j=8,sum;
 printf("\n\n�п�J�����Ҹ��X�G");
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
   printf("\n�������ҬO���Ī�\n");
   if (a[1]==8)
    printf("�o�O�k�ͪ������� ,");
   else if (a[1]==16)
    printf("�o�O�k�ͪ������� ,");
   switch(a[0])
    {
     case 10:
	printf("�Ҧb�a���x�_��");break;
     case 11:
	printf("�Ҧb�a���x����");break;
     case 12:
	printf("�Ҧb�a���򶩥�");break;
     case 13:
	printf("�Ҧb�a���x�n��");break;
     case 14:
	printf("�Ҧb�a��������");break;
     case 15:
	printf("�Ҧb�a���x�_��");break;
     case 16:
	printf("�Ҧb�a���y����");break;
     case 17:
	printf("�Ҧb�a����鿤");break;
     case 18:
	printf("�Ҧb�a���s�˿�");break;
     case 19:
	printf("�Ҧb�a���]�߿�");break;
     case 20:
	printf("�Ҧb�a���x����");break;
     case 21:
	printf("�Ҧb�a���n�뿤");break;
     case 22:
	printf("�Ҧb�a�����ƿ�");break;
     case 23:
	printf("�Ҧb�a�����L��");break;
     case 24:
	printf("�Ҧb�a���Ÿq��");break;
     case 25:
	printf("�Ҧb�a���x�n��");break;
     case 26:
	printf("�Ҧb�a��������");break;
     case 27:
	printf("�Ҧb�a���̪F��");break;
     case 28:
	printf("�Ҧb�a���Ὤ��");break;
     case 29:
	printf("�Ҧb�a���x�F��");break;
     case 30:
	printf("�Ҧb�a�����");break;
     case 31:
	printf("�Ҧb�a�������s");break;
     case 32:
	printf("�Ҧb�a��������");break;
     case 33:
	printf("�Ҧb�a���s����");break;
     case 34:
	printf("�Ҧb�a���Ÿq��");break;
     case 35:
	printf("�Ҧb�a���s�˥�");break;
    }
  }
 else
   printf("�������ҬO�L�Ī�\n");

}