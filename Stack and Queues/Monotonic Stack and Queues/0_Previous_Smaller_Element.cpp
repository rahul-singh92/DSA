#include <iostream>
using namespace std;

vector<int> previous_smal_ele(vector<int>& arr)
{
    vector<int> res(arr.size());
    stack<int> st;

    for(int i = 0; i < arr.size(); i++)
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
    vector<int> arr = {5, 7, 9, 6 ,7, 4, 5, 1, 3, 7};
    vector<int> res = previous_smal_ele(arr);

    for(auto i : res) cout<<i<<" ";
}