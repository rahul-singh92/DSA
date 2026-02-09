#include <iostream>
using namespace std;

vector<int> prev_smal_ele(vector<int>& arr)
{
    vector<int> res(arr.size());
    stack<int> st;

    for(int i = 0; i < 2 * arr.size(); i++)
    {
        while(!st.empty() && st.top() >= arr[i % arr.size()])
        {
            st.pop();
        }

        if(i >= arr.size())
        {
            res[i % arr.size()] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i % arr.size()]);
    }
    return res;
}

int main()
{
    vector<int> arr = {5, 7, 9, 6 ,7, 4, 5, 1, 3, 7};
    vector<int> ans = prev_smal_ele(arr);

    for(auto i: ans) cout<<i<<" "; 
}