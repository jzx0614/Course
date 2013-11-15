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
	int lookup,tmp,choose,i=0;
	head=malloc(sizeof(struct list));
	p=head;
	do{
	printf("\n\n1.ADD:\n2.Delete:\n3.List All:\n4.Exit:\nchoose 1~4 :");
	scanf("%d",&choose);
	clrscr();
	switch(choose)
	 {
		case 1:
			printf("\nInput:");
			if(i==0)
			{	scanf("%d",&head->data);
				head->next=NULL;
			}
			else
			{       q=t=head;
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
			break;
		case 2:
			q=t=head;
			printf("Input: ");
			scanf("%d",&lookup);
			while(t!=NULL&&lookup!=t->data)
			{ q=t; t=t->next ;}
			if(t==NULL)
				{printf("there is no num.\n");}
			else if(t==head)
				{head=head->next;}
			else
				{q->next=t->next;}
			break;
		case 3:
			t=head;
			printf("\nnum:");
			while(t!=NULL)
			{
				printf(" %d",t->data);
				t = t->next;
			}
			break;
	 }


	}while(0<choose&&choose<4);
}