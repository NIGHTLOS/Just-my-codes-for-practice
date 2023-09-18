#include<bits/stdc++.h>
using namespace std;

typedef struct LNode{
    int dat;
    struct LNode *next;
}node,*linklist;

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

void chaifen(linklist &La,linklist &Lb,linklist &Lc)
{
    node *pa,*pb,*pc,*qa,*qb;
    La=new node;
    Lb=new node;
    La->next=NULL;
    Lb->next=NULL;
    qa=La,qb=Lb;
    pa=new node;
    pb=new node;
    pc=Lc->next;
    while(pc)
    {
        if(pc->dat%2!=0)
        {
            int x=pc->dat;
            pa->dat=x;
            pa->next=qa->next;
            qa->next=pa;
            qa=pa;
            pa=new LNode;
        }
        else
        {
            int x=pc->dat;
            pb->dat=x;
            pb->next=qb->next;
            qb->next=pb;
            qb=pb;
            pb=new LNode;
        }
        pc=pc->next;
    }
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
    linklist La,Lb,Lc;
    create(Lc);
    chaifen(La,Lb,Lc);
    outputList(La);
    outputList(Lb);
    return 0;
}

