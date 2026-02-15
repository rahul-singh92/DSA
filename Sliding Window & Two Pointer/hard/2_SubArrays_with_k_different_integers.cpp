#include <iostream>
using namespace std;

int bru_way(vector<int>& arr, int k)
{
    int maxLen = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        unordered_map<int, int> mpp;
        for(int j = i; j < arr.size(); j++)
        {
            mpp[arr[j]]++;

            if(mpp.size() == k) maxLen++;
            else if(mpp.size() > k) break;
        }
    }
    return maxLen;
}

int atMostK(vector<int>& arr, int k)
{
    if(k == 0 || arr.empty()) return 0;
    int l = 0, r = 0;
    int res = 0;
    unordered_map<int, int> mpp;
    while(r < arr.size())
    {
        // if a new element
        if(mpp[arr[r]] == 0) k--;

        mpp[arr[r]]++;

        while(k < 0)
        {
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) k++;

            l++;
        }

        res += (r - l + 1);
        r++;
    }
    return res;
}

int op_way(vector<int>& arr, int k)
{
    return atMostK(arr, k) - atMostK(arr, k - 1);
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 3};

    int ans = op_way(arr, 2);

    cout<<ans<<endl;
}