#include <bits/stdc++.h>
const int N=505;
using namespace std;
typedef struct{
    int *base;
    int front;
    int rear;//��β
}sqe;

void init_queue_re(sqe &Q)
{
    Q.base=new int[N];
    /*if(!Q.base)
    {
        exit(OVERFLOW);   //����ʧ��
    }*/
    Q.front=Q.rear=0;
}

void input(sqe &Q,int x)
{
    if((Q.rear+1)%N==Q.front)
    {
        printf("����������\n");
    }
    Q.base[Q.rear]=x;
    Q.rear=(Q.rear+1)%N;
}

void del_queue_re(sqe &Q,int &x)//ȫ��ɾ�����ӣ�����û��
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
