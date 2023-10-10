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
/*void insert(node *h,int x)
{

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
    //create_tail(La);
    create_head(La);
    outputList(La);
    return 0;
}

