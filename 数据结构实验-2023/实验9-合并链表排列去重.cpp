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

void unions(linklist &la,linklist &lb)//合并链表，最后都到La
{
    node *pa,*pb,*pc,*lc;
    pa=la->next;
    pb=lb->next;
    lc=la;
    pc=lc;
    while(pa&&pb)//其中一个为空退出
    {
        if(pa->dat>pb->dat)
        {
            pc->next=pa;//pc指向pa 数据放入lc
            pc=pa;
            pa=pa->next;//排完了下一个
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
        pc->next=pa;//剩下的指pa
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
    while(p)//直接暴力枚举所有重复结点
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
    LNode *pre ,*p,*t;//建立前驱节点pre，删除的节点t
    while(L->next!=NULL)//从头遍历
    {
        pre=L;//前驱直接指向头节点
        p=L->next;//遍历所有节点
        while(p->next!=NULL)//从当前开始找，时间还是O(n^2)
        {
            if(pre->next->dat > p->next->dat)//相当于p节点元素比后面大，就把pre变成p节点
            {
                pre=p;
            }
            p=p->next;//这样找出最小的
        }
        cout<<pre->next->dat<<" ";//输出找到的最小值，把这个节点删掉即可
        t=pre->next;//t节点删除
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
