#include <iostream>
using namespace std;

//Time Complexity O(n * 2^n)
vector<int> BitMask_Method_Brute(vector<int>& arr)
{
    int n = arr.size();
    vector<int> sums;

    //Iterate through all possible mask from 0 to 2 ^ n - 1
    for(int mask = 0; mask < (1 << n); mask++)  // O(2^n)
    {
        int sum = 0;
        for(int i = 0; i < n; i++) //O(n)
        {
            //If i-th bit is set take it
            if(mask & (1 << i)) sum += arr[i];
        }
        sums.push_back(sum);
    }
    sort(sums.begin(), sums.end());

    return sums;
}

void findSum(int index, int cur_s, vector<int>& arr, vector<int>& sums)
{
    //Base Case: If we have considered all elements

    if(index == arr.size())
    {
        sums.push_back(cur_s);
        return;
    }

    // Include current element
    findSum(index + 1, cur_s + arr[index], arr, sums);

    //Do not include
    findSum(index + 1, cur_s, arr, sums);
}

vector<int> recurOp(vector<int>& arr)
{
    vector<int> sums;
    findSum(0, 0, arr, sums);
    sort(sums.begin(), sums.end());
    return sums;
}

int main()
{
    vector<int> arr = {5, 2, 1};

    vector<int> result = recurOp(arr);

    for(int i : result) cout<<i<<" ";
    cout<<endl;
}