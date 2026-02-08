#include <iostream>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for(auto i: s)
    {
        if(i == '(' || i == '{' || i == '[')
            st.push(i);
        else
        {
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if((i == ')' && ch == '(') || 
               (i == '}' && ch == '{') ||
               (i == ']' && ch == '['))
            {
                continue;
            }
            else return false;
        }
    }
    return st.empty();
}

int main()
{
    string s = "()[{}()]";
    
    if(isValid(s))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}
