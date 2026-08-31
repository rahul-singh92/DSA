#include <iostream>
using namespace std;

vector<int> lis_way(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    vector<int> dp(arr.size(), 1), hash(arr.size());

    int maxi = 1;
    int lastIndex = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        hash[i] = i;
        for(int j = 0; j < i; j++)
        {
            if(arr[i] % arr[j] == 0 && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if(dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(lastIndex != hash[lastIndex])
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int main()
{
    vector<int> arr = {16, 8, 2, 4, 32};

    vector<int> ans = lis_way(arr);
    for(auto x: ans) cout<<x<<" ";
    cout<<endl;
}