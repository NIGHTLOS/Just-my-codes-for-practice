#include <stdio.h>
#include <stdlib.h>
typedef struct x
{
    int a;
    struct x *next;
}node;
int main()
{
    int n,i,k;
    while(~scanf("%d",&n))
    {
        node *head,*p,*q;
        head = (node*)malloc(sizeof(node));
        p = q = head;
        for(i=0;i<n;i++)
        {
            p = (node*)malloc(sizeof(node));
            scanf("%d",&p->a);
            q->next = p;
            q = p;
        }
        q->next = NULL;
        scanf("%d",&k);
        node *t = head;
        while(1)
        {
            if(t->next==NULL)
            {
                p = (node*)malloc(sizeof(node));
                p->a = k;
                t->next=p;
                p->next =NULL;
                break;
            }
            if(t->next->a>k)
            {
                p = (node*)malloc(sizeof(node));
                p->a = k;
                p->next = t->next;
                t->next=p;
                break;
            }
            t = t->next;
        }
        head = head->next;
        while(1)
        {
            if(head->next!=NULL)
            printf("%d  ",head->a);
            else
            {
            printf("%d\n",head->a);
            break;
            }
            head = head->next;
        }
        free(p);
    }
    return 0;
}

