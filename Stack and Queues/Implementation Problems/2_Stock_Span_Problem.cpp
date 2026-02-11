#include <iostream>
using namespace std;

vector<int> bru_way(vector<int>& arr)
{
    int n = arr.size();

    vector<int> res(n);

    for(int i = 0; i < n; i++)
    {
        int curSpan = 0;
        for(int j = i; j >= 0 ; j--)
        {
            if(arr[j] <= arr[i]) curSpan++;
            else break;
        }
        res[i] = curSpan;
    }
    return res;
}

vector<int> findPGE(vector<int>& arr)
{
    int n = arr.size();

    vector<int> res(n);

    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        // Get the current elemet
        int curEle = arr[i];

        while(!st.empty() && arr[st.top()] <= curEle)
        {
            st.pop();
        }

        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        st.push(i);
    }
    return res;
}

vector<int> op_way(vector<int>& arr)
{
    int n = arr.size();
    vector<int> PGE = findPGE(arr);

    vector<int> ans(n);

    for(int i = 0; i < n; i++)
    {
        ans[i] = i - PGE[i];
    }
    
    return ans;
}

int main()
{
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};

    vector<int> ans = op_way(arr);

    for(auto i : ans) cout<<i<<" ";
}