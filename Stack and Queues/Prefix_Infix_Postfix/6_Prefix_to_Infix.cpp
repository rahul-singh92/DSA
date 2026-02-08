#include <iostream>
using namespace std;

int prec(char c)
{
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    return -1;
}

void prefixToInfix(string s)
{
    int l = s.length();
    reverse(s.begin(), s.end());

    for(int i = 0; i < l; i++)
    {
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }

    s = '(' + s + ')';
    stack<char> st;
    string result;

    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            result += ch;
        
        else if(ch == '(')
            st.push(ch);

        else if(ch == ')')
        {
            while(st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); //For removing (
        }

        else
        {
            if(ch == '^')
            {
                while(prec(s[i]) <= prec(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
            }
            else
            {
                while(prec(s[i]) < prec(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(ch);
        }
    }
    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    cout<<result<<endl;
}

int main()
{
    string s = "(p+q)*(m-n)";
    prefixToInfix(s);
}