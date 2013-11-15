#include <stdio.h>
int main (int argc, char *argv[])
{
 FILE *fin,*fout;
 char list;
 int i=1,up=0,low=0;
 if(argc!=3)
        printf("command eroror\n");
 else
         {
                fin=fopen(argv[1],"r");
                fout=fopen(argv[2],"w");
				fprintf(fout,"1.");
				while((list=getc(fin))!=EOF)
                {
					if(list=='\n')
						fprintf(fout,"\n%d.",++i);
					else
						putc(list,fout);
                }
                fclose(fin);
				fclose(fout);
   
         }
return 0;
}
