#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void show(struct node *h,int x)
{
	struct node *q;
	q=h->next;//ͷ���û�����ݣ�ֱ����һ����ʼ 
	while(q!=NULL)
		{
			if(q->data==x)
			{
				printf("%dû��ǰ��\n",x);
				break; 
			}
			if(q->next!=NULL&&q->next->data==x)
			{
				printf("%d\n",q->data);
				break;
			}
			if(q->next==NULL)
			{
				printf("%d������\n",x);
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
		//h->data=-99999;ͷ���Ϊ�յ�β�巨 
		p=h;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			p->next=(struct node*)malloc(sizeof(struct node));//p��һ����ͷ��㣬��Ҫ��������	
			p=p->next;//p������ͷ�����һ�����Ѿ���p����һ��Ȼ��p�������� 
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
