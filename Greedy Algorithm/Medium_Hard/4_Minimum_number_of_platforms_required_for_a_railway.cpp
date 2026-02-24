#include <iostream>
using namespace std;

int bru_way(int n, int arr[], int dep[])
{
    int ans = 1;

    for(int i = 0; i < n; i++)
    {
        int count = 1;

        for(int j = i + 1; j < n; j++)
        {
            if((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
               (arr[j] >= arr[i] && arr[j] <= dep[i])) count++;
        }
        ans = max(ans,count);
    }
    return ans;
}

int op_way(int n, int arr[], int dep[])
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platform = 1;
    int result = 1;
    int i = 1, j = 0;

    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }

        result = max(result, platform);
    }
    return result;
}

int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};

    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = op_way(n, arr, dep);

    cout<<ans<<endl;
}