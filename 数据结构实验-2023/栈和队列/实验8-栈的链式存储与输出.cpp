#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int dat;
    struct node *next;
}linkstack;


linkstack *input(linkstack *top,int x) //入栈，比较类似头插法
{
    linkstack *p;
    p=new linkstack;
    p->dat=x;
    p->next=top;
    top=p;
    return top;
}

linkstack *pop_out(linkstack *top,int *x)//出栈
{
    linkstack *p;
    if(!top)
    {
        return nullptr;
    }
    p=top;
    *x=p->dat;
    top=top->next;
    free(p);
    return top;
}

int main()
{
    linkstack *L;
    int x;
    int cnt=0;
    while(cin>>x&&x!=0)
    {
        L=input(L,x);
        cnt++;
    }
    for(int i=0;i<cnt;i++)
    {
        L= pop_out(L,&x);
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
