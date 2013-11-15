{
    len=length($0)
    flag=0;
}
{
    if(len>=12){
	printf("%s-",substr($0,0,len-9))
	flag=1;
    }
    else if(len==11) printf("%s-",substr($0,0,len-10))
}
(len>=10&&flag==0){printf("%s-",substr($0,len-9,3))}
(len>=9 &&flag==1){printf("%s-",substr($0,len-8,2))}
(len>=7) {printf("%s-",substr($0,len-6,3))}
(len>=4) {print substr($0,len-3,4)}


