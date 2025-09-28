#include <iostream>
using namespace std;

int maxOne(int arr[],int n)
{
    int count = 0,max_count = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == 1)
        {
            count++;
        }
        else
        {
            if(count > max_count)
            {
                max_count = count;
            }
            count = 0;
        }
    }
    if (count > max_count) {
        max_count = count;
    }

    return max_count;
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int maxO = maxOne(arr,n);
    cout<<maxO;
}