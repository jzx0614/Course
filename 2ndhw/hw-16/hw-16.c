#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct list
{
	int data;
	struct list *next;
};

void main()
{
	struct list *head,*p,*q,*t;
	int i=0;
	head=malloc(sizeof(struct list));
	p=head;
	while(i<5)
	{
			printf("\nInput:");
			
			if(i==0)
			{	scanf("%d",&head->data);
				head->next=NULL;
			}
			else
			{   q=t=head;
				p=malloc(sizeof(struct list));
				scanf("%d",&p->data);
				while(q!=NULL&&((q->data)<=(p->data)))
				{t=q;q=q->next;}
					if(q==NULL)
					    {t->next=p;p->next=NULL;}
					else if(q==head)
					    {p->next=head;head=p; }
					else
					    {t->next=p;p->next=q; }
			}
			i++;
	}

			t=head;
			printf("\nnum:");
			while(t!=NULL)
			{
				printf(" %d",t->data);
				t = t->next;
			}
		
}