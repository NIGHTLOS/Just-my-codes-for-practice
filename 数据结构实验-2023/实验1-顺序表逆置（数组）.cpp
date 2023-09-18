#include<bits/stdc++.h>
using namespace std;
int res[5005];

int main()
{
    int n;
    cin>>n;
    memset(res,0,sizeof(res));
    for(int i=1;i<=n;i++)
    {
        cin>>res[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    for(int i=1,j=n;i<j;i++,j--)
    {
        int tmp=res[i];
        res[i]=res[j];
        res[j]=tmp;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}

