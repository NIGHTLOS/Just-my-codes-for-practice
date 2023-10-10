#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    int x;
    while(cin>>x&&x!=0)
    {
        st.push(x);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
