#include <iostream>
using namespace std;

// 2 10 12 1 11 --- 2 10 12 1 11 ---> hypothetically double the array
vector<int> next_greater_ele_2(vector<int>& arr)
{
    vector<int> res(arr.size());
    stack<int> st;

    for(int i = 2 * arr.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= arr[i % arr.size()])
        {
            st.pop();
        }

        if(i < arr.size())
        {
            res[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i % arr.size()]);
    }
    return res;
}

int main()
{
    vector<int> arr = {2, 10, 12, 1, 11};
    vector<int> ans = next_greater_ele_2(arr);

    for(auto i : ans) cout<<i<<" ";
}