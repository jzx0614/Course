#include<time.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>


void main()
{
	time_t t;
	struct tm *p;
	t=time(NULL);
	p=localtime(&t);
	printf("今天是%d年%d月%d日(星期%d)",p->tm_year+1900,p->tm_mon+1,p->tm_mday,p->tm_wday);

}