#include <iostream>
using namespace std;

long long int solve(vector<int>& arr)
{
    int n = arr.size();

    if(n == 1) return arr[0];

    long long int prev1 = arr[0];
    long long int prev2 = 0;

    for(int i = 1; i < n; i++)
    {
        long long int pick = arr[i];
        if(i > 1) pick += prev2;

        long long int notPick = prev1;

        long long int cur_i = max(pick, notPick);

        prev2 = prev1;
        prev1 = cur_i;
    }
    return prev1;
}

long long int rob(vector<int>& arr, int n)
{
    //if no house
    if(n == 0) return 0;
    //if only one house
    if(n == 1) return arr[0];

    vector<int> arr1, arr2;
    for(int i = 0; i < n; i++)
    {
        if(i != 0) arr1.push_back(arr[i]);
        if(i != n - 1) arr2.push_back(arr[i]);
    }

    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    return max(ans1, ans2);
}

int main()
{
    vector<int> arr = {1, 5, 1, 2, 6};
    int n = arr.size();

    cout<<rob(arr, n);
}