#include <iostream>
using namespace std;

vector<int> next_smal_ele(vector<int> &arr)
{
    vector<int> res(arr.size());
    stack<int> st;

    for(int i = arr.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}

int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> res = next_smal_ele(arr);

    for(auto i: res) cout<<i<<" ";
    cout<<endl;
}