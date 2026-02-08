#include <iostream>
using namespace std;

void postfixToInfix(string s)
{
    stack<string> st;

    for(int i = 0; i < s.length(); i++)
    {
        if(isalnum(s[i])) st.push(string(1, s[i]));

        else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            st.push('(' + op1 + s[i] + op2 +')');
        }
    }
    cout<<st.top()<<endl;
}
int main()
{
    string s = "AB-DE+F*/";
    postfixToInfix(s);
}