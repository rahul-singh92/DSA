#include <iostream>
using namespace std;

int sol(vector<vector<int>>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), 0));

    for(int i = 0; i < arr.size(); i++) dp[i][0] = arr[i][0];
    for(int j = 0; j < arr[0].size(); j++) dp[0][j] = arr[0][j];

    int sum = 0;
    for(int i = 1; i < arr.size(); i++)
    {
        for(int j = 1; j < arr[0].size(); j++)
        {
            if(arr[i][j] == 1)
            {
                dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
            }
            else dp[i][j] = 0;
        }
    }

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            sum += dp[i][j];
        }
    }
    return sum;
}

int main()
{
    vector<vector<int>> arr = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};

    int ans = sol(arr);
    cout<<ans<<endl;
}