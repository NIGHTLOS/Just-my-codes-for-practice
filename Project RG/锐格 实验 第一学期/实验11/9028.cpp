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
	struct node *p=head;//ͷ�巨��ͷ������� 
	scanf("%d",&p->data);
	head->next=NULL;
	for(i=1;i<n;i++)
	{
		struct node *q=(struct node*)malloc(sizeof(struct node));//���ٽڵ�
		q->next=head;//����ͷ�ڵ�
		head=q;//�ı�ͷ��� 
		p=q;
		scanf("%d",&p->data);//��ͷ�ڵ��������
	}
	p=head;//���һ����Ϊͷ��� 
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
