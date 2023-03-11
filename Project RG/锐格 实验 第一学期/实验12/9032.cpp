#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void show(struct node *h,int x)
{
	struct node *q;
	q=h->next;//头结点没有数据，直接下一个开始 
	while(q!=NULL)
		{
			if(q->data==x)
			{
				printf("%d没有前驱\n",x);
				break; 
			}
			if(q->next!=NULL&&q->next->data==x)
			{
				printf("%d\n",q->data);
				break;
			}
			if(q->next==NULL)
			{
				printf("%d不存在\n",x);
				break;
			}
			q=q->next;
		}
}
int main()
{
	int n,i,x,t;
	while(~scanf("%d",&n))
	{
		struct node *h,*p,*q;
		h=(struct node*)malloc(sizeof(struct node));
		h->next=NULL;
		//h->data=-99999;头结点为空的尾插法 
		p=h;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			p->next=(struct node*)malloc(sizeof(struct node));//p第一次是头结点，不要输入数据	
			p=p->next;//p现在是头结点下一个，已经把p换下一个然后p输入数据 
			p->data=t; 
		}
		p->next=NULL;
		scanf("%d",&x);
		show(h,x);
		free(p);
		free(q);
	}
	return 0;
}
