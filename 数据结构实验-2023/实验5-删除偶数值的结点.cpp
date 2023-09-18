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
    linklist pre;
    pre=L;
    p=pre->next;
    while(p!=NULL)
    {
        if(p->dat%2==0)
        {
            pre->next=p->next;
            free(p);
            p=pre->next;
        }
        else
        {
            p=p->next;
            pre=pre->next;
        }
    }
}

/*void del(linklist &L)
{
    L=new node;
    node *p,*pre;

}*/


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
    linklist La;
    create(La);
    //del(La);
    outputList(La);
    return 0;
}

