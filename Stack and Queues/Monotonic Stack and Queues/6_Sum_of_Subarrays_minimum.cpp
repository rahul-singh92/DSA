#include <iostream>
using namespace std;

int bru_way(vector<int>& arr)
{
    int n = arr.size();
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        int mini = arr[i];
        for(int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            total += mini;
        }
    }
    return total;
}

vector<int> findNSE(vector<int>& arr)
{
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--)
    {
        int curEle = arr[i];

        while(!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        res[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return res;
}

vector<int> findPSEE(vector<int>& arr)
{
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        int curEle = arr[i];

        while(!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return res;
}

int op_way(vector<int>& arr)
{
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    int n = arr.size();
    int mod = 1e9 + 7;

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int left = i - psee[i];

        int right = nse[i] - i;

        long long freq = left * right * 1LL;

        int val = (freq * arr[i] * 1LL) % mod;

        sum = (sum + val) % mod;
    }
    return sum;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int ans = op_way(arr);
    cout<<ans<<endl;
}