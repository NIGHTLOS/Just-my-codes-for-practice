#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main()
{
    int n,i,x;
    while(scanf("%d",&n)!=-1)
    {
        struct node *h,*p,*q,*t;
        h=(struct node *)malloc(sizeof(struct node));
        p=q=h;
        for(i=1;i<=n;i++)
        {
            p=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&p->data);
            q->next=p;
            q=p;
        }
        q->next=NULL;
        scanf("%d",&x);
        //h=del(h,x);
        p = h;
        q = p->next;
        if(h == NULL)
        {
           printf("THE HEAD POINT TO NULL\n");
           return 0;
        }
        while(q!= NULL)
        { 
           if(q->data == x)
          {
            p->next = q->next;
            free(q);
            q = p->next;
          }
        else
          {
            p = p->next;
            q = q->next;
          }
        }    
        if(h != NULL && h->data == x)
        {
           t = h;
           h = t->next;
           free(t);
        }
        p=h->next;
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
