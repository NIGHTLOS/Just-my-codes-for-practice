#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};

void create_tail(struct node **h,int n)
{
	*h=(struct node *)malloc(sizeof(struct node));
	struct node *p,*q;
	p=q=*h;
	for(int i=1;i<=n;i++)
	{
		p=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		q->next=p;
		q=p;
	}
	q->next=NULL;
}

struct node *search(struct node *h,int x,int *w) 
{
    int i = 0; 
	struct node *p = h, *q = NULL;
    while(p)
    {
	  if (p->data == x)
	   {
		q = p;
		*w = i;
		break;
	   }
	  p = p->next;
	  i++;
    }
    return q;
}

int main()
{
	int n,x;
	while(~scanf("%d",&n))
	{
	  struct node *h = NULL;
	  int w;
	  create_tail(&h,n);
	  scanf("%d",&x);
	  struct node *result = search(h,x,&w);
	  if(result==NULL)
	  {
	  	printf("0\n");
	  }
	  else
	  {
	  	printf("%d %d\n",w,x);
	  }
	}
	return 0;
}
