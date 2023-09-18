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
    create(La);
    outputList(La);
    return 0;
}
