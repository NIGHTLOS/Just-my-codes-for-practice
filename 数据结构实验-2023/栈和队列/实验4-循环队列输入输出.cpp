#include <bits/stdc++.h>
const int N=505;
using namespace std;
typedef struct{
    int *base;
    int front;
    int rear;//队尾
}sqe;

void init_queue_re(sqe &Q)
{
    Q.base=new int[N];
    /*if(!Q.base)
    {
        exit(OVERFLOW);   //分配失败
    }*/
    Q.front=Q.rear=0;
}

void input(sqe &Q,int x)
{
    if((Q.rear+1)%N==Q.front)
    {
        printf("队列已满！\n");
    }
    Q.base[Q.rear]=x;
    Q.rear=(Q.rear+1)%N;
}

void del_queue_re(sqe &Q,int &x)//全部删除出队，这里没用
{
    /*if(Q.front==Q.rear)
    {
        return ERROR;
    }*/
    x=Q.base[Q.front];
    Q.front=(Q.front+1)%N;
}

void output_front(sqe &Q)
{
    while(Q.front!=Q.rear)
    {
        cout<<Q.base[Q.front]<<" ";
        Q.front=(Q.front+1)%N;
    }
    cout<<endl;
}

int main()
{
    sqe Qs;
    init_queue_re(Qs);
    int x;
    while(cin>>x&&x!=0)
    {
        input(Qs,x);
    }
    output_front(Qs);
    return 0;
}
