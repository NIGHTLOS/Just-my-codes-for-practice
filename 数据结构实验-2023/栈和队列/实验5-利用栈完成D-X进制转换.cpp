#include<bits/stdc++.h>
using namespace std;
const int N= 1005;
typedef long long int lli;

struct st{
    int top;
    int dat[N];
};

int empty_st(st &S)
{
    if(S.top>=N)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pop_st(st &S)
{
    if(empty_st(S))
    {
        cout<<"Õ»¿Õ"<<endl;
    }
    else
    {
        S.top++;
    }
}

void input(st &S,int x)
{
    if(S.top==0)
    {
        cout<<"stack is in max size!"<<endl;
    }
    else
    {
        S.top--;
        S.dat[S.top]=x;
    }
}

void init_stack(st &S)
{
    S.top=N;
}

void dec_turn(int n,int x,st &S)
{
    while(n)
    {
        input(S,n%x);
        n/=x;
    }
}

void output_st(st &S)
{
    while(!empty_st(S))
    {
        if(S.dat[S.top]>=10)
        {
            cout<<"`";
            cout<<S.dat[S.top];
            cout<<"`";
            pop_st(S);
        }
        else
        {
            cout<<S.dat[S.top];
            pop_st(S);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    st Sk;
    init_stack(Sk);
    lli ans;
    dec_turn(n,m,Sk);
    cout<<n<<"(10)=";
    output_st(Sk);
    cout<<"("<<m<<")"<<endl;
    return 0;
}


