#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;
    char ch;
    int flag=1;
    while(cin>>ch)
    {
        if(ch=='#')
        {
            break;
        }
        if(ch=='('||ch=='['||ch=='{')
        {
            st.push(ch);
        }
        else if(ch==')'||ch==']'||ch=='}')
        {
            if(st.empty())
            {
                flag=0;
                break;
            }
            else
            {
                char c=st.top();
                if((c=='('&&ch==')')||(c=='['&&ch==']')||(c=='{'&&ch=='}'))
                {
                    st.pop();
                    flag=1;
                    continue;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        else
        {
            continue;
        }
    }
    if(flag==1&&st.empty())
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }
}
