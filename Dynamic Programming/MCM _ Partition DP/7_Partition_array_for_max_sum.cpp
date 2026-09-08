#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int k, int i)
{
    if(i == arr.size()) return 0;

    int len = 0, maxEle = INT_MIN;
    int maxAns = 0;
    for(int j = i; j < min((int)arr.size(), i + k); j++)
    {
        len++;
        maxEle = max(maxEle, arr[j]);

        int sum = maxEle * len + rec_way(arr, k, j + 1);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}

int solve_memoWay(vector<int>& arr, vector<int>& dp, int k, int i)
{
    if(i == arr.size()) return 0;

    if(dp[i] != -1) return dp[i];

    int len = 0, maxEle = INT_MIN;
    int maxAns = 0;
    for(int j = i; j < min((int)arr.size(),i + k); j++)
    {
        len++;
        maxEle = max(maxEle, arr[j]);

        int sum = len * maxEle + solve_memoWay(arr, dp, k, j + 1);
        maxAns = max(maxAns, sum);
    }
    return dp[i] = maxAns;
}

int memo_way(vector<int>& arr, int k)
{
    vector<int> dp(arr.size(), -1);
    return solve_memoWay(arr, dp, k, 0);
}

int tabu_way(vector<int>& arr, int k)
{
    vector<int> dp(arr.size() + 1, 0);

    for(int i = arr.size() - 1; i >= 0; i--)
    {
        int len = 0, maxEle = INT_MIN;
        int maxAns = 0;
        for(int j = i; j < min((int)arr.size(), i + k); j++)
        {
            len++;
            maxEle = max(maxEle, arr[j]);

            int sum = len * maxEle + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[i] = maxAns;
    }
    return dp[0];
}

int main()
{
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    // int ans = rec_way(arr, k, 0);
    int ans = memo_way(arr, k);
    cout<<ans<<endl;
}