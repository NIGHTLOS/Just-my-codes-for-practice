#include <bits/stdc++.h>
using namespace std;
typedef struct QNode{
    int dat;
    struct QNode *next;
}qn,*queuepts;

typedef struct{
    queuepts fr;
    queuepts ed;
}linkqueue;

void init_queue(linkqueue &Q)
{
    Q.fr=Q.ed=new qn;
    Q.fr->next=nullptr;
}

void input(linkqueue &Q,int x)
{
    queuepts p=new qn;
    p->dat=x;
    p->next=NULL;
    Q.ed->next=p;
    Q.ed=p;
}

int out_queue(linkqueue &Q,int &x)//从队头开始清空，这里用不到
{
    if(Q.fr==Q.ed)
    {
        return -1;
    }
    queuepts p=Q.fr->next;
    if(Q.ed==p)
    {
        Q.ed=Q.fr;
    }
    delete p;
    return 0;
}

void output(linkqueue &Q)
{
    queuepts p=Q.fr->next;
    while(p)
    {
        cout<<p->dat<<" ";
        p=p->next;
    }
    cout<<endl;
}

signed main()
{
    linkqueue Qs;
    init_queue(Qs);
    int x;
    while(cin>>x&&x!=0)
    {
        input(Qs,x);
    }
    output(Qs);
    return 0;
}
