#include <iostream>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    stack<int> st;
    int maxArea = 0;
    
    heights.push_back(0); // add 0 at end for edge case
    for(int i = 0; i < heights.size(); i++)
    {
        while(!st.empty() && heights[st.top()] > heights[i])
        {
            int height = heights[st.top()];
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }
    return maxArea;
}

int maxi(vector<vector<int>>& matrix)
{
    if(matrix.empty()) return 0;

    int m = matrix[0].size(); //Number of columns

    vector<int> height(m, 0);

    int maxArea = 0;

    for(auto& row: matrix)
    {
        for(int i = 0; i < m; i++)
        {
            if(row[i] == '1') height[i]++;
            else height[i] = 0;
        }

        maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
}

int main()
{
    vector<vector<int>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    int ans = maxi(matrix);
    cout<<ans<<endl;
}