#include <stdio.h>
int main (int argc, char *argv[])
{
 FILE *fin;
 char list;
 int i=0,up=0,low=0;
 if(argc!=2)
        printf("command eroror\n");
 else
         {
                fin=fopen(argv[1],"r");
                while((list=getc(fin))!=EOF)
                {
                        if(('A'<=list)&&(list<='Z'))
                                up++;
                        else if (('a'<=list)&&(list<='z'))
                                low++;
                }
                fclose(fin);
                printf("Upper case = %d \nLower case = %d\n",up,low);
         }
return 0;
}
