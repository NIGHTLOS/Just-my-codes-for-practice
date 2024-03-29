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
    cout<<endl;//可有可无
    return 0;
}

