#include <iostream>
using namespace std;

int bru_way(vector<int>& arr, int k)
{
    int n = arr.size();
    int maxSub = 0;

    for(int i = 0; i < n; i++)
    {
        int count_odd = 0;
        for(int j = i; j < n; j++)
        {
            if(arr[j] % 2 != 0) count_odd++;

            if(count_odd == k) maxSub++;
        }
    }
    return maxSub;
}

int bet_way(vector<int>& arr, int k)
{
    unordered_map<int, int> freq;

    //Base
    freq[0] = 1;

    int oddCount = 0;
    int result = 0;

    for(int i: arr)
    {
        if(i % 2 == 1) oddCount++;

        if(freq.count(oddCount - k))
        {
            result +=  freq[oddCount - k];
        }

        freq[oddCount]++;
    }
    return result;
}

int countAtMost(vector<int>& arr, int k)
{
    int l = 0, r = 0;
    int res = 0;

    while(r < arr.size())
    {
        if(arr[r] % 2 != 0) k--;

        while(k < 0)
        {
            if(arr[l] % 2 != 0) k++;
            l++;
        }

        res += (r - l + 1);
        r++;
    }
    return res;
}

int op_way(vector<int>& arr, int k)
{
    return countAtMost(arr, k) - countAtMost(arr, k - 1);
}

int main()
{
    vector<int> arr = {1, 1, 2, 1, 1};

    int ans = op_way(arr, 3);
    cout<<ans<<endl;
}