#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
    struct node *next;
};
int main()
{
	int n,i,x;
	while(scanf("%d",&n)!=-1)
	{
		struct node *head,*p,*q;
		head=(struct node *)malloc(sizeof(struct node));
	    p=q=head;//尾插法且头结点有数 
	    for(i=1;i<=n;i++)
	    {
	    	p=(struct node *)malloc(sizeof(struct node));
			scanf("%d",&p->data);
	    	q->next=p;
	    	q=p;
		}
		q->next=NULL;
		p=head->next;
		while(1)
		{
			if(p->next==NULL)
			{
				printf("%d\n",p->data);
				break;
			}
			else
			{
				printf("%d  ",p->data);
			}
			p=p->next;
		}
		free(p);
	}
    return 0;
}
