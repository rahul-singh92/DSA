#include <iostream>
using namespace std;

int sol(vector<int>& arr)
{
    int n = arr.size();

    // LIS
    vector<int> dp1(n, 1);
    int max_len = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && dp1[i] < 1 + dp1[j])
                dp1[i] = 1 + dp1[j];
        }
    }

    // LDS - Longest Decreasing Sequence
    vector<int> dp2(n, 1);
    
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(arr[i] > arr[j] && dp2[i] < dp2[j] + 1)
                dp2[i] = 1 + dp2[j];
        }
    }

    for(int i = 0; i < n; i++)
        max_len = max(max_len, dp1[i] + dp2[i] - 1);
    return max_len;
}

int main()
{
    vector<int> arr = {5, 1, 4, 2, 3, 6, 8, 7};

    int ans = sol(arr);
    cout<<ans<<endl;
}