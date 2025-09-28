#include <iostream>
#include <vector>
using namespace std;

vector<int> mat_in_sp(vector<vector<int>> vec, int n , int m )
{
    int top = 0, left = 0, bottom = n - 1, right = m - 1;
    vector<int> ans;

    while(top <= bottom && left <= right)
    {
        //right 
        for(int i = left; i <= right; i++)
        {
            ans.push_back(vec[top][i]);
        }
        top++;
        //top to bottom
        for(int i = top; i <= bottom;i++)
        {
            ans.push_back(vec[i][right]);
        }
        right--;
        if(top <= bottom)
        {
            //left to right 
            for(int i = right; i >= left;i--)
            {
                ans.push_back(vec[bottom][i]);
            }
            bottom--;
        }
        if(left <= right)
        {
            //bottom to top
            for(int i = bottom; i >= top;i--)
            {
                ans.push_back(vec[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n, vector<int>(m,0));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }
    vector<int> ans = mat_in_sp(vec,n,m);
    cout<<endl;
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}