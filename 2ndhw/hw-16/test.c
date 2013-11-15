#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
};

int  main()
{
	struct list *head=NULL,*tail=NULL,*p,*q,*t;
	int i=0;
	while(i++<5)
	{	
			p=malloc(sizeof(struct list));
			printf("Input:");
			scanf("%d",&p->data);
			p->next=NULL;
			if(head=NULL)
			{head=p;tail=p;}
			else
		        {	
			for(head=q;q!=NULL&&(q->data)<=(p->data);q=q->next)
			    {t=q;}
			if(q==NULL)
			    {t->next=p;}
			else if(q==head)	
    	                    {p->next=head;head=p; }
			else
			    {t->next=p;p->next=q; }
			}printf("\n");
	}
			printf("\nnum:");
			for(p=head;p!=NULL;p=p->next)
			{printf(" %d",t->data);}		
	return 0;
}
