#include <iostream>
using namespace std;

vector<int> findNSE(vector<int>& arr)
{
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--)
    {
        int curEle = arr[i];

        while(!st.empty() && arr[st.top()] > curEle)
        {
            st.pop();
        }

        res[i] = st.empty() ? n : st.top();

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

        while(!st.empty() && arr[st.top()] > curEle)
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return res;
}

vector<int> findNGE(vector<int>& arr)
{
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--)
    {
        int curEle = arr[i];

        while(!st.empty() && arr[st.top()] <= curEle)
        {
            st.pop();
        }

        res[i] = st.empty() ? n : st.top();

        st.push(i);
    }
    return res;
}

vector<int> findPGEE(vector<int>& arr)
{
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        int curEle = arr[i];

        while(!st.empty() && arr[st.top()] < curEle)
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return res;
}

long long sumSubarrayMinimum(vector<int>& arr)
{
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    int n = arr.size();
    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = left * right * 1LL;
        long long val = freq * arr[i] * 1LL;

        sum += val;
    }

    return sum; 
}

long long sumSubarrayMaximum(vector<int>& arr)
{
    vector<int> nge = findNGE(arr);

    vector<int> pgee = findPGEE(arr);

    int n = arr.size();
    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        int left = i - pgee[i];

        int right = nge[i] - i;

        long long freq = left * right * 1LL;

        long long val = freq * arr[i] * 1LL;

        sum += val;
    }

    return sum;
}

long long op_way(vector<int>& arr)
{
    return (
        sumSubarrayMaximum(arr) - sumSubarrayMinimum(arr)
    );
}

int main()
{
    vector<int> arr = {1, 2, 3};
    long long ans = op_way(arr);
    cout<<ans<<endl;
}