#include <iostream>
using namespace std;

void prefixToPostfix(string s)
{
    stack<string> st;

    for(int i = s.length() - 1; i >= 0; i--)
    {
        if(isalnum(s[i])) st.push(string(1, s[i]));

        else
        {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            st.push(op1 + op2 + s[i]);
        }
    }
    cout<<st.top()<<endl;
}

int main()
{
    string s = "/-AB*+DEF";
    prefixToPostfix(s);
}