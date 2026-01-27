#include <iostream>
#include <algorithm>
using namespace std;

void Sub(int ind, vector<int> arr, int n, int target, vector<vector<int>>& ans, vector<int>& ds)
{
    //If target beacome 0 we found valid combination
    if(target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for(int i = ind; i < n; i++)
    {
        //Skip Duplicates
        if(i > ind && arr[i] == arr[i-1]) continue;

        //If current element is greater than the remaining target, break the loop
        if(arr[i] > target) break;

        ds.push_back(arr[i]);

        Sub(i + 1, arr, n, target - arr[i], ans, ds);

        ds.pop_back();
    }
}

vector<vector<int>> printAll(vector<int> arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;

    Sub(0, arr, n, target, ans, ds);
    return ans;
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int n = 7;
    int target = 8;

    vector<vector<int>> ans = printAll(arr, n, target);
    for(auto i : ans)
    {
        for(auto b: i)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
}