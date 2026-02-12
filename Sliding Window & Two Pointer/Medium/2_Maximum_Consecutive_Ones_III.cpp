#include <iostream>
using namespace std;

int bru_way(vector<int>& arr, int k)
{
    int maxLen = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        int zeros = 0;
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[j] == 0) zeros++;

            if(zeros > k) break;

            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

int bet_way(vector<int>& arr, int k)
{
    int maxLen = 0;
    int l = 0, r = 0;
    int zeros = 0;

    while(r < arr.size())
    {
        if(arr[r] == 0) zeros++;
        
        while(zeros > k)
        {
            if(arr[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}

int op_way(vector<int>& arr, int k)
{
    int maxlen = 0;
    int l = 0, r = 0, zeros = 0;

    while(r < arr.size())
    {
        if(arr[r] == 0) zeros++;

        if(zeros > k)
        {
            if(arr[l] == 0) zeros--;
            l++;
        }

        if(zeros <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 3;

    int ans = op_way(arr, k);
    cout<<ans<<endl;
}