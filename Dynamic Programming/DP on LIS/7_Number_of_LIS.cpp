#include <iostream>
using namespace std;

int sol(vector<int>& arr)
{
    int n = arr.size();
    
    vector<int> dp(n, 1), cnt(n, 1);

    int maxi = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = 1 + dp[j];
                cnt[i] = cnt[j];
            }
            else if(arr[j] < arr[i] && dp[i] == dp[j] + 1)
            {
                cnt[i] += cnt[j];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        if(dp[i] == maxi) ans += cnt[i];
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 5, 4, 7};

    int ans = sol(arr);
    cout<<ans<<endl;
}