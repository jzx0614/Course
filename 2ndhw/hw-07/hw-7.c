#include<stdio.h>
int swap (char *p)
{
        if ('a'<=*p&&*p<='z')
                *p=*p-32;
        return 0;
}
int main (int argc , char *argv[])
{
        FILE *fin,*fout;
        char ch;
        if (argc!=3)
                printf("command error\n");
        else
        {
                fin =fopen(argv[1],"r");
                fout=fopen(argv[2],"w");
                while((ch=getc(fin))!=EOF)
                {
                        swap(&ch);
                        putc(ch,fout);
                }

                fclose(fin);
                fclose(fout);
        }
        return 0;
}
