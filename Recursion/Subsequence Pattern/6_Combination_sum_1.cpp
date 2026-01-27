#include <iostream>
using namespace std;

void printAllSub(int ind, int arr[], int c_s, vector<int>& ds, int n, int s)
{
    if(c_s > s) return;
    if(ind == n)
    {
        if(c_s == s)
        {
            for(auto i : ds) cout<<i<<" ";
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    c_s += arr[ind];

    printAllSub(ind, arr, c_s, ds, n, s);

    ds.pop_back();
    c_s -= arr[ind];

    printAllSub(ind + 1, arr, c_s, ds, n, s);
    
    return;
}

//Another way without using c_s and keeping code minimal

void findComb(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds)
{
    if(ind == arr.size())
    {
        if(target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if(arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        findComb(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    findComb(ind + 1, target, arr, ans, ds);
}

vector<vector<int>> comB(vector<int>& arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findComb(0, target, arr, ans, ds);
    return ans;
}

int main()
{
    int arr[] = {2, 3, 6, 7};
    int n = 4;
    int s = 7;
    vector<int> ds;
    printAllSub(0, arr, 0, ds, n, s);
}