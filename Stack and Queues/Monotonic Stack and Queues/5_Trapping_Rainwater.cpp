#include <iostream>
using namespace std;

//1. Use array traversal at each point tarverse and find the largest and in right the largest and then calculate
// time --> O(n * (n + n))
int bru_way(vector<int>& arr)
{
    int total = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        int maxLeft = 0, maxRight = 0;

        for(int j = 0; j <= i; j++)
        {
            if(arr[j] > maxLeft) maxLeft = arr[j];
        }
        
        for(int j = i; j < n; j++)
        {
            if(arr[j] > maxRight) maxRight = arr[j];
        }

        total += min(maxLeft, maxRight) - arr[i];
    }
    return total;
}

//2. In this create a "prefixSum" and "suffixSum" as ans array and see from it which one is greater in left and right
// Time --> O(n + n + n)   Space ---> O(n + n)
int bet_way(vector<int>& arr)
{
    int n = arr.size();
    vector<int> prefixSum(n), suffixSum(n);

    prefixSum[0] = arr[0], suffixSum[0] = arr[n-1]; 
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = max(prefixSum[i-1], arr[i]);
    }

    for(int j = n - 2; j >= 0; j--)
    {
        suffixSum[j] = max(suffixSum[j+1], arr[j]);
    }

    int total = 0;
    int leftMax = 0, rightMax = 0;
    for(int i = 0; i < n; i++)
    {
        leftMax = prefixSum[i];
        rightMax = suffixSum[i];

        if(arr[i] < leftMax && arr[i] < rightMax)
        {
            total += min(leftMax, rightMax) - arr[i];
        }
    }
    return total;
}

//Now the problem is size 
// So use now two pointer method where we will move the poiinter which will be smaller
// Time --> 

int op_way(vector<int>& arr)
{
    int leftMax = 0, rightMax = 0;
    int l = 0, r = arr.size() - 1;
    int total = 0;

    while(l < r)
    {
        if(arr[l] <= arr[r])
        {
            if(leftMax > arr[l]) total += leftMax - arr[l];
            else leftMax = arr[l];

            l++;
        }
        else
        {
            if(rightMax > arr[r]) total += rightMax - arr[r];
            else rightMax = arr[r];

            r--;
        }
    }
    return total;
}

int main()
{
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    int ans = op_way(arr);
    cout<<ans<<endl;
}