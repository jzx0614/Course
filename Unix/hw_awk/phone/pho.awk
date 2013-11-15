BEGIN{
    len=length(ARGV[1])
    flag=0
    if(len>=12){
	printf("%s-",substr(ARGV[1],0,len-9))
	flag=1;
    }
    else if(len==11) printf("%s-",substr(ARGV[1],0,len-10))
    
    if(len>=10&&flag==0){printf("%s-",substr(ARGV[1],len-9,3))}
    if(len>=9 &&flag==0){printf("%s-",substr(ARGV[1],len-8,2))}
    if(len>=7) {printf("%s-",substr(ARGV[1],len-6,3))}
    if(len>=4) {print substr(ARGV[1],len-3,4)}
}
