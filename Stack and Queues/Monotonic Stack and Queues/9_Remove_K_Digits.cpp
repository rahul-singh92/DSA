#include <iostream>
using namespace std;

string remove_k(string s, int k)
{
    stack<char> st;

    for(int i = 0; i < s.size(); i++)
    {
        char digit = s[i];

        //Pop last digit if possible or if a smaller digit is found
        while(!st.empty() && k > 0 && st.top() > digit)
        {
            st.pop();
            k--;
        }

        st.push(digit);
    }

    while(!st.empty() && k > 0)
    {
        st.pop();
        k--;
    }

    if(st.empty()) return "0";

    string res = "";

    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    while(res.size() > 0 && res.back() == '0') res.pop_back();

    reverse(res.begin(), res.end());

    if(res.empty()) return "0";

    return res;
}

int main()
{
    string s = "541892";
    int k = 2;

    string ans = remove_k(s, k);

    cout<<ans<<endl;
}