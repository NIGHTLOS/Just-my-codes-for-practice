#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
int main()
{
	int i,n;
	while(~scanf("%d",&n))
	{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	struct node *p=head;//头插法且头结点有数 
	scanf("%d",&p->data);
	head->next=NULL;
	for(i=1;i<n;i++)
	{
		struct node *q=(struct node*)malloc(sizeof(struct node));//开辟节点
		q->next=head;//插入头节点
		head=q;//改变头结点 
		p=q;
		scanf("%d",&p->data);//对头节点进行输入
	}
	p=head;//最后一个数为头结点 
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
