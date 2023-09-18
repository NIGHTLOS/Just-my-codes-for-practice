#include<bits/stdc++.h>
using namespace std;
typedef struct LNode{
    int dat;
    struct LNode *next;
}node,*linklist;

void create_tail(linklist &L)
{
    linklist p,q;
    L=new LNode;
    L->next=NULL;
    q=L;
    p=new LNode;
    int x;
    while(cin>>x&&x!=0)
    {
        p->dat=x;
        p->next=q->next;
        q->next=p;
        q=p;
        p=new LNode;
    }
}

void insert(linklist &L)
{
    LNode *pre ,*p,*t;//����ǰ���ڵ�pre��ɾ���Ľڵ�t
    while(L->next!=NULL)//��ͷ����
    {
        pre=L;//ǰ��ֱ��ָ��ͷ�ڵ�
        p=L->next;//�������нڵ�
        while(p->next!=NULL)//�ӵ�ǰ��ʼ�ң�ʱ�仹��O(n^2)
        {
            if(pre->next->dat > p->next->dat)//�൱��p�ڵ�Ԫ�رȺ���󣬾Ͱ�pre���p�ڵ�
            {
                pre=p;
            }
            p=p->next;//�����ҳ���С��
        }
        cout<<pre->next->dat<<" ";//����ҵ�����Сֵ��������ڵ�ɾ������
        t=pre->next;//t�ڵ�ɾ��
        pre->next=t->next;
        free(t);
    }
    free(L);
}

void create_head(linklist &L)
{
	linklist p,q;
	L=new LNode;
	L->next=NULL;
	int x;
	while(cin>>x&&x!=0)
	{
		p=new LNode;
		p->dat=x;
		p->next=L->next;
		L->next=p;
	}
}


int main()
{
    linklist La;
    create_tail(La);
    insert(La);
    cout<<endl;//���п���
    return 0;
}

