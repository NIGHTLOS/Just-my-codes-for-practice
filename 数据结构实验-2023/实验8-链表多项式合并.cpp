#include<bits/stdc++.h>
using namespace std;

typedef struct LNode{
    int dat;
    int pw;
    struct LNode *next;
}node,*linklist;
int lena,lenb;
int maxpow=-99999;

void create(linklist &L,int n)
{
    linklist p,q;
    L=new LNode;
    L->next=NULL;
    q=L;
    p=new LNode;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d,%d",&x,&y);
        if(maxpow<y)
        {
            maxpow=y;
        }
        p->dat=x;
        p->pw=y;
        p->next=q->next;
        q->next=p;
        q=p;
        p=new LNode;
    }
}

void js(linklist &La,linklist &Lb,linklist &Lc)
{
    node *pa,*pb,*pc,*qc;
    Lc=new node;
    Lc->next=NULL;
    qc=Lc;
    pc=new LNode;
    pa=La->next;
    pb=Lb->next;
    int len=max(lena,lenb);
    for(int i=1;i<=maxpow;i++)
    {
        pc->dat=0;
        pc->pw=i;
        pc->next=qc->next;
        qc->next=pc;
        qc=pc;
        pc=new LNode;
    }
    linklist t=Lc->next;
    while(t)
    {
        for(int j=1;j<=len;j++)
        {
            if(pa!=NULL&&pa->pw==t->pw)
            {
                t->dat+=pa->dat;
                pa=pa->next;
            }
            if(pb!=NULL&&pb->pw==t->pw)
            {
                t->dat+=pb->dat;
                pb=pb->next;
            }
        }
        t=t->next;
    }
}

void outputList(linklist L)
{
    linklist p;
    p=L->next;
    while(p!=NULL)
    {
        if(p->dat!=0)
        {
            cout<<p->dat<<"*"<<"x^"<<p->pw<<" ";
        }
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    linklist La,Lb,Lc;
    create(La,n);
    lena=n;
    cin>>n;
    create(Lb,n);
    lenb=n;
    js(La,Lb,Lc);
    //cout<<maxpow<<" "<<lena<<" "<<lenb<<endl;
    outputList(Lc);
    return 0;
}

