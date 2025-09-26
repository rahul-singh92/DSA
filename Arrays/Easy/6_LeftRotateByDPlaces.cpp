#include <iostream>
#include <algorithm>
using namespace std;
void brute(int *arr,int n,int d)
{
    d %= n;
    int *temp = new int[d];
    for(int i = 0;i<d;i++)
    {
        temp[i] = arr[i];
    }
    for(int i = d;i<n;i++)
    {
        arr[i-d] = arr[i];
    }
    int j = 0;
    for(int i = n-d;i<n;i++)
    {
        arr[i] = temp[j++];   //or you can use arr[i] = arr[i-(n-d)];
    }
}

void optimal(int *arr,int n,int d)
{
    // [1,2,3,4,5] d= 2
    // [2,1] [5,4,3] and then again reverse whole array
    // [3,4,5,1,2]

    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
}

/*
If you are not allowed to use reverse function

void reverse(int *arr,int start,int end)
{
    while(start<=end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

*/

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int d;
    cin>>d;
    brute(arr,n,d);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}