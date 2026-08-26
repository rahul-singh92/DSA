#include <iostream>
using namespace std;

int bru_way(vector<int>& arr)
{
    int ans = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i+1; j < arr.size(); j++)
        {
            ans = max(ans, arr[j] - arr[i]);
        }
    }
    return ans;
}

int op_way(vector<int>& arr)
{
    int ans = 0;

    int mini = INT_MAX;
    for(int i = 0; i < arr.size(); i++)
    {
        mini = min(arr[i], mini);
        ans = max(arr[i] - mini, ans);
    }
    return ans;
}

int main()
{
    vector<int> arr = {7,1,5,3,6,4};

    // int ans = bru_way(arr);
    int ans = op_way(arr);
    cout<<ans<<endl;
}