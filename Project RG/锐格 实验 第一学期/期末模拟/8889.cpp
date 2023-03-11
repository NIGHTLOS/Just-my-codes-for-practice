#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}LNode;
void Creat(LNode *H)
{
    int x;
    LNode *s,*t;
    scanf("%d",&x);
    while(x!=0)
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x; 
        s->next=H->next;
        H->next=s;
        scanf("%d",&x);
    }
}
//start
void hanshu(LNode *h)
{
	int max=-999;
	LNode *p,*q,*tmp;
	p=h;
	///q=NULL;
	while(p->next!=NULL)
	{
		if(p->next->data>max)
		{
			max=p->next->data;
			q=p;
			//t=p;
			//free(t);
		}
		p=p->next;
	}
	//q=(LNode * )malloc(sizeof(struct node));
	tmp=q->next;
	q->next=q->next->next;
	tmp->next=h->next;
	h->next=tmp;
}
//end
void Out(LNode *B)
 {
 	LNode *p;
	 p=B->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
 }
int main()
{
    LNode *B;
    B=(LNode *)malloc(sizeof(LNode));B->next=NULL;
    Creat(B);
    hanshu(B);
    Out(B);
    return 0;
}
