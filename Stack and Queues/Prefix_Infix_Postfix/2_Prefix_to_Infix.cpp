#include <iostream>
using namespace std;

void prefixToInfix(string s)
{
    stack<string> st;

    for(int i = s.length() - 1; i >= 0; i--)
    {
        if(isalnum(s[i])) st.push(string(1, s[i]));

        else
        {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            st.push('(' + op1 + s[i] + op2 + ')');
        }
    }
    cout<<st.top()<<endl;
}

int main()
{
    string s = "*+PQ-MN";
    prefixToInfix(s);
}