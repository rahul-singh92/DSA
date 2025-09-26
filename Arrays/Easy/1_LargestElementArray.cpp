#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l = INT_MIN;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] > l) l = arr[i];
    }

    cout<<"Largest Element in Array "<<l<<endl;
}