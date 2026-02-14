#include <iostream>
using namespace std;

int bru_way(vector<int>& arr, int k)
{
    int maxCount = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for(int j = i; j < arr.size(); j++)
        {
            count += arr[j];
            if(count == k)
            {
                maxCount++;
            }
            else if(count > k) break;
        }
    }
    return maxCount;
}

int bet_way(vector<int>& arr, int k)
{
    unordered_map<int, int> mpp;

    int count = 0, sum = 0;

    mpp[0] = 1;

    for(auto i: arr)
    {
        sum += i;

        if(mpp.find(sum - k) != mpp.end())
        {
            count += mpp[sum - k];
        }
        mpp[sum]++;
    }

    return count;
}

int atMost(vector<int>& arr, int k)
{
    if(k < 0) return 0;

    int l = 0, r = 0;
    int sum = 0, count = 0;

    while(r < arr.size())
    {
        sum += arr[r];

        while(sum > k)
        {
            sum -= arr[l];
            l++;
        }

        count += (r - l + 1);
        r++;
    }
    return count;
}

int op_way(vector<int>& arr, int k)
{
    // To calculate it we will findSubArray <= k and findSubArray <= k - 1 and then subtract

    return atMost(arr, k) - atMost(arr, k - 1);
}

int main()
{
    vector<int> arr = {1, 0, 0, 1, 1, 0};

    int ans = op_way(arr, 2);

    cout<<ans<<endl;
}