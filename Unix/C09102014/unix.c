#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>

int width=80,height=20;

void show_header(char *buff, int N)
{
    time_t t=time(NULL);
    struct tm *p;
    int space,i;
    char output[81];
    system("clear");			    //clear screen
    while(strstr(buff,"/")!=NULL)	    //get filename
	strcpy(buff,strstr(buff,"/")+1);
    strcpy(output,buff);
    space=N-strlen(buff)-31;		    //measure space
    for(i=0;i<space;i++)    strcat(output," ");
    if(space<0)		    strcat(output," ");
    strcat(output,ctime(&t));		    //get Date and time
    output[strlen(output)-1]='\0';	    //clear "\n"
    strcat(output," ²�Ӱa");		    //name
    printf("%s\n",output);		    //output headline
}

void read_argv(char *argv)
{
    FILE *fin;
    char buff[100];
    int h=0;
    DIR *x;
    struct dirent *dir;
    if((x=opendir(argv))!=NULL){	    //Isdir? and open dir
	while((dir=readdir(x))!=NULL){	    //read dir
	    if((strcmp(dir->d_name,".")!=0)&&(strcmp(dir->d_name,"..")!=0)){
		strcpy(buff,argv);	    
		strcat(buff,"/");
		strcat(buff,dir->d_name);   //get filename
		read_argv(buff);
	    }
	}
	closedir(x);
    }
    else if((fin=fopen(argv,"r"))==NULL){   //open file
	printf("can't open file.");
	getchar();
    }
    else{
	while(fgets(buff,100,fin)!=NULL){   //read a line in file
	    if((strlen(buff)-1)<=width){    //judge width
		if((h%height)==0){	    //stop and enter to next page. 
		    if(h!=0){
			printf("--Press Enter to next page.--");
			getchar();
		    }
		    show_header(argv,width);
		}
		printf("%s",buff);	    //show file
		h++;			    //count height
	    }
				
	}
	fclose(fin);
	printf("--Press Enter to close file.--");
	getchar();			    //stop and enter to next file
	system("clear");
    }
}
int main(int argc,char *argv[])
{
    if(argc==1)
	printf("command error, no file");
    else
	while(--argc>0){	
	    if(*(++argv)[0]=='-'){
		switch((*argv)[1]){	    //set width and height
		    case 'w':width=atoi(*++argv); break;
		    case 'l':height=atoi(*++argv);break;
		    default: printf("%s isn't commnad.\n",*argv); 
		}
	    if(width>80) width=80;	    //MAX width
	    if(height>22) height=22;	    //MAX height
	    --argc;	
	    }
	    else{
		read_argv(*argv);
	    }
	}
    return 0;
}
