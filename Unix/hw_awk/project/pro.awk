BEGIN{
    FS  = ":"
    OFS = ":"
    count=0
}
{
    if(FILENAME=="programmer")
	people[$1]=$5
    if(FILENAME=="project"){
	str=sprintf("%s:%d:%d",$1,$4,$5)
	project[count++]=str
	hour[$4]+=$5	
	project_m[$1]=0
    }
}
END{
    for(item in people)
    {
	if(hour[item]!=0)
	    people[item]/=hour[item]
	else
	    people[item]=0
    }
    for(i=0;i<count;i++){
	project_m[substr(project[i],0,6)]+=people[substr(project[i],8,3)]*substr(project[i],12,1)
    }
    for(item in project_m)
	print item,project_m[item]
}

