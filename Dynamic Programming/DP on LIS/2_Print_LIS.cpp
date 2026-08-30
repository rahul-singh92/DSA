#include <iostream>
using namespace std;

vector<int> LIS(vector<int>& arr)
{
    vector<int> dp(arr.size(), 1), hash(arr.size());

    int maxi = 1;
    int lastIndex = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++)
        {
            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> lis;
    lis.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis.push_back(arr[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    vector<int> ans = LIS(arr);
    for(auto x: ans)
        cout<<x<<" ";
    cout<<endl;
}