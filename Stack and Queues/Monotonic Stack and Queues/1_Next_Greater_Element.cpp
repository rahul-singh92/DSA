#include <iostream>
using namespace std;

vector<int> next_greater_ele(vector<int>& arr)
{
    vector<int> res(arr.size());
    stack<int> st;

    for(int i = arr.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if(st.empty()) res[i] = -1;
        else {
            res[i] = st.top();
        }

        st.push(arr[i]);
    }

    return res;
}

int main()
{
    vector<int> arr = {6, 0, 8, 1, 3};
    vector<int> ans = next_greater_ele(arr);

    for(auto i : ans) cout << i<<" ";
    cout<<endl;
}