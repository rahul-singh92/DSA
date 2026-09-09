#include <iostream>
using namespace std;

int larArea1(vector<int>& height)
{
    int maxArea = 0;

    for(int i = 0; i < height.size(); i++)
    {
        int minHeight = INT_MAX;
        for(int j = i; j < height.size(); j++)
        {
            minHeight = min(minHeight, height[j]);

            int width = j - i + 1;
            int area = width * minHeight;

            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

int larArea2(vector<int>& height)
{
    stack<int> st;

    vector<int> pre(height.size(), 0);
    vector<int> pos(height.size(), 0);

    for(int i = 0; i < height.size(); i++)
    {
        while(!st.empty() && height[st.top()] >= height[i])
        {
            st.pop();
        }

        pre[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = height.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && height[st.top()] >= height[i])
        {
            st.pop();
        }

        pos[i] = st.empty() ? height.size() - 1 : st.top() - 1;
        st.push(i);
    }

    int maxArea = 0;
    for(int i = 0; i < height.size(); i++)
    {
        int width = pos[i] - pre[i] + 1;
        maxArea = max(maxArea, width * height[i]);
    }
    return maxArea;
}

int larArea3(vector<int>& height)
{
    stack<int> st;

    int maxArea = 0;
    for(int i = 0; i <= height.size(); i++)
    {
        while(!st.empty() && (i == height.size() || height[st.top()] >= height[i]))
        {
            int h = height[st.top()];
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
            maxArea = max(maxArea, width * h);
        }
        st.push(i);
    }
    return maxArea;
}

int sol(vector<vector<int>>& arr)
{
    int maxArea = 0;

    vector<int> heinght(arr[0].size(), 0);
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(arr[i][j] == 1) heinght[j]++;
            else heinght[j] = 0;
        }
        // int area = larArea1(heinght);
        // int area = larArea2(heinght);
        int area = larArea3(heinght);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> arr = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};

    int ans = sol(arr);
    cout<<ans<<endl;
}