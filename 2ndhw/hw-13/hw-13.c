#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
	struct list
	{
		char num[20];
		char user[20];
		char bir[20];
		char ph[20];
		struct list *next;
	};
void main()

{	int i=0,choose;
	struct list *t,*p,*q,*r,*head;
	char lookup[20];
	head=malloc(sizeof(struct list));
	p=head;
	do{
		printf("\n(1)Add:\n(2)Delete\n(3)List\n(4)Update\n(5)Quit\n\nPlease select 1~5 function: ");
		scanf("%d",&choose);
		clrscr();
		switch(choose)
		{
		case 1:
			q=head;
			printf("\nNum:");
			scanf("%s",lookup);
			if(i>0)
			{
				while(q!=NULL&&strcmp(lookup,q->num))q=q->next;
				if(q!=NULL){printf("the same num\n");break;}
				p -> next= malloc(sizeof(struct list));
				p = p->next;
			}
			strcpy(p->num,lookup);
			printf("User:");
			scanf("%s",p->user);
			printf("Birthday:");
			scanf("%s",p->bir);
			printf("Phone:");
			scanf("%s",p->ph);
			p -> next = NULL;
			i++;

			break;
		case 2:
			q=r=head;
			printf("Input a num:");
			scanf("%s",&lookup);
			while(q!=NULL&&strcmp(lookup,q->num))
			{
				r=q;
				q=q->next;
			}
			if(q==NULL)
				printf("\nThere isn't this num.\n");
			else if (q==head)
				 head=head->next;
			else
				r->next=q->next;

			break;
		case 3:
			t=head;
			while(t!=NULL)
			{
				printf("\nNum:%s\n",t->num);
				printf("User:%s\n",t->user);
				printf("Birthday:%s\n",t->bir);
				printf("Phone:%s\n",t->ph);
				t = t->next;
			}
			break;
		case 4:
			q=head;
			printf("Input a update num:");
			scanf("%s",lookup);

			while(q!=NULL&&strcmp(lookup,q->num))
				q=q->next;

			if(q==NULL)
			{
				printf("\nThere isn't this num.\n");
				break;
			}

			printf("User:");
			scanf("%s",q->user);
			printf("Birthday:");
			scanf("%s",q->bir);
			printf("Phone:");
			scanf("%s",q->ph);
			break;
		}
	}while(1<=choose&&choose<=4);
}