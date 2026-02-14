#include <iostream>
using namespace std;

int bru_way(vector<int>& arr, int k)
{
    int n = arr.size();

    int maxSum = 0;

    for(int i = 0; i <= k; i++)
    {
        int tempSum = 0;

        for(int j = 0; j < i; j++)
        {
            tempSum += arr[j];
        }

        for(int j = 0; j < k - i; j++)
        {
            tempSum += arr[n - 1 - j];
        }

        maxSum = max(maxSum, tempSum);
    }
    return maxSum;
}

int op_way(vector<int>& arr, int k)
{
    int n = arr.size();

    int total = 0;

    for(int i = 0; i < k; i++)
    {
        total += arr[i];
    }

    int maxPoints = total;

    for(int i = 0; i < k; i++)
    {
        total -= arr[k - 1 - i];

        total += arr[n - 1 - i];

        maxPoints = max(maxPoints, total);
    }
    return maxPoints;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    int ans = op_way(arr, 3);

    cout<<ans<<endl;
}