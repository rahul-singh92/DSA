#include <iostream>
using namespace std;
void bruteapp(int *arr,int n)
{
    int temp = arr[0];
    if(n>1)
    {
        for(int i = 1;i<n;i++)
        {
            arr[i-1] = arr[i];
        }
        arr[n-1] = temp;
    }
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
    bruteapp(arr,n);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}