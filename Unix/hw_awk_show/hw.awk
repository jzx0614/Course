BEGIN{  
	argcnum=ARGC
	for(i=1;i<=argcnum;i++){
	    if(ARGV[i]=="-l")
	    {
		height=ARGV[++i]
		ARGC-=2
	    }
	    else if(ARGV[i]=="-w")
	    {
		width=ARGV[++i]
		ARGC-=2
	    }
	}

	if(argcnum==ARGC)
	{
	    height=22
	    width=80
	}
	else
	{
	    for(i=1;i<=argcnum-ARGC;++i)
		ARGV[i]=ARGV[argcnum-ARGC+i]
	    if(height>22) height=22
	    if(width>80)  width=80
	}
}
    (FNR==1) {height_count=0}
    (length($0)<=width){
        if(height_count++ % height==0)
	{
	    system("sleep 1")
	    system("clear")
    
	    "echo $USER"| getline name 
	    "date"| getline date1

	    str= sprintf("%s %s",date1,name)
	    space= width-length(FILENAME)-length(str)-1
	
	    printf ("%s",FILENAME)
	    for(i=0;i<space;i++)
		printf(" ");
	    print strspace,str
	}
	print height_count,$0
    }

