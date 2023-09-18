#include<bits/stdc++.h>
using namespace std;
typedef struct LNode{
    int dat;
    struct LNode *next;
}node,*linklist;
linklist La,Lb;

void create(linklist &L)
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

void unions(linklist &la,linklist &lb)//�ϲ�������󶼵�La
{
    node *pa,*pb,*pc,*lc;
    pa=la->next;
    pb=lb->next;
    lc=la;
    pc=lc;
    while(pa&&pb)//����һ��Ϊ���˳�
    {
        if(pa->dat>pb->dat)
        {
            pc->next=pa;//pcָ��pa ���ݷ���lc
            pc=pa;
            pa=pa->next;//��������һ��
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    if(pa)
    {
        pc->next=pa;//ʣ�µ�ָpa
    }
    else
    {
        pc->next=pb;
    }
    delete lb;
}

void remove(linklist &L)
{
    node *p,*q,*t;
    p=L->next;
    while(p)//ֱ�ӱ���ö�������ظ����
    {
        q=p;
        while(q->next)
        {
            if(q->next->dat==p->dat)
            {
                t=q->next;
                q->next=t->next;
                free(t);
            }
            else
            {
                q=q->next;
            }
        }
        p=p->next;
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

void outputList(linklist L)
{
    linklist p;
    p=L->next;
    while(p!=NULL)
    {
        cout<<p->dat<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    create(La);
    create(Lb);
    unions(La,Lb);
    remove(La);
    insert(La);
    //outputList(La);
    return 0;
}
