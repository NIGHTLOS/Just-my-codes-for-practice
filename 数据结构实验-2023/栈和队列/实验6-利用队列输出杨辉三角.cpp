#include<bits/stdc++.h>
using namespace  std;
const int M=1005;

typedef struct SqQueue{
    int data[M];
    int front,rear;
}sq;

void init_queue(sq &Q)
{
    Q.rear=Q.front=0;
}

bool empty_sq(sq Q)
{
    if(Q.rear==Q.front)
        return true;
    return false;
}

bool input(sq &Q,int x)
{
    if((Q.rear+1)%M==Q.front)
    {
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%M;
    return true;
}

int out_sq(sq &Q,int &x)
{
    if(empty_sq(Q))
    {
        return 0;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%M;
    return 1;
}

bool queue_top(sq Q,int &x)
{
    if(empty_sq(Q))
    {
        return false;
    }
    x=Q.data[Q.front];
    return true;
}

int main()
{
    int n;
    cin>>n;
    sq Q;
    init_queue(Q);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<"  ";
        }
        printf("%2d  ",1);
        for(int k=3;k<=i;k++)
        {
            int x,e;
            out_sq(Q,x);
            queue_top(Q,e);
            input(Q,x+e);
            printf("%2d  ",x+e);
        }
        if(i!=1)
        {
            printf("%2d  ",1);
        }
        input(Q,1);
        cout<<endl;
    }
    return 0;
}
