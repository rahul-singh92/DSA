#include <iostream>
using namespace std;

//O(n*n)
int bru_way(vector<int>& arr)
{
    int n = arr.size();
    int maxArea = 0;

    for(int i = 0; i < n; i++)
    {
        int minHeight = INT_MAX;
        for(int j = i; j < n; j++)
        {
            minHeight = min(minHeight, arr[j]);

            int width = j - i + 1;
            int area = width * minHeight;

            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

//O(2n + 2n + n)
int op_way_1(vector<int>& arr)
{
    int n = arr.size();
    stack<int> st;

    vector<int> leftSmall(n), rightSmall(n);

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        leftSmall[i] = st.empty() ? 0 : st.top() + 1;

        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        rightSmall[i] = st.empty() ? n - 1 : st.top() - 1;

        st.push(i);
    }

    int maxA = 0;
    for(int i = 0; i < n; i++)
    {
        int width = rightSmall[i] - leftSmall[i] + 1;
        maxA = max(maxA, arr[i] * width);
    }
    return maxA;
}

int op_way_2(vector<int>& arr)
{
    stack<int> st;
    int maxA = 0;
    int n = arr.size();

    for(int i = 0; i <= n; i++)
    {
        while(!st.empty() && ( i == n || arr[st.top()] >= arr[i]))
        {
            int height = arr[st.top()];
            st.pop();

            int width;
            if(st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }

            maxA = max(maxA, width * height);
        }

        st.push(i);
    }
    return maxA;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3, 1};
    int ans = op_way_2(arr);
    cout<<ans<<endl;
}