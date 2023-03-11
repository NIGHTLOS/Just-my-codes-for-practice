#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}LNode;
//start
void Creat(LNode *h)
{
    int x;
    LNode *p,*q;
    p = q = h;
    scanf("%d",&x);
    while(x!=0)
    {
        p=(LNode *)malloc(sizeof(LNode));
        p->data = x;
        q->next = p;
        q=p;
        scanf("%d",&x);
    }
    q->next=NULL;
}
void Link(LNode *A,LNode *B)
{
	LNode *p1;
	p1=B;
	while(p1->next!=NULL)
	{
	    p1=p1->next;
	}
	p1->next=A->next;	
}
//end
int main()
{
    LNode *A,*B,*p;
    A=(LNode *)malloc(sizeof(LNode));A->next=NULL;
    B=(LNode *)malloc(sizeof(LNode));B->next=NULL;
    Creat(A);
    Creat(B);
    Link(A,B);
    p=B->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
} 
