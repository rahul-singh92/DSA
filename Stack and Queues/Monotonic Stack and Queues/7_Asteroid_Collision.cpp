#include <iostream>
using namespace std;

vector<int> op_way(vector<int>& arr)
{
    int n = arr.size();
    vector<int> st;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > 0) st.push_back(arr[i]);
        else
        {
            while(!st.empty() && st.back() > 0 && st.back() < abs(arr[i]))
            {
                st.pop_back();
            }

            if(!st.empty() && st.back() == abs(arr[i])) st.pop_back();

            else if(st.empty() || st.back() < 0) st.push_back(arr[i]);
        }
    }
    return st;
}

int main()
{
    vector<int> arr = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    vector<int> ans = op_way(arr);

    for(auto i: ans) cout<<i<<" ";
}