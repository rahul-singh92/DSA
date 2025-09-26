#include <iostream>
#include <algorithm>
using namespace std;

int missingEle(int arr[],int n)
{
    int i = 0,j = 1;
    for(j; j!=n-1;j++)
    {
        if(arr[j] != arr[i] + 1)
        {
            return arr[i]+1;
            break;
        }
        i++;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n-1];
    for(int i = 0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    int ans = missingEle(arr,n);
    cout<<ans;
}