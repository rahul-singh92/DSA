#include <iostream>
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
    int t = 0;
    for(int i = 1;i<n;i++)
    {
        if(arr[i] < arr[i-1])
        {
            t++;
            break;
        }
    }
    if(t) cout<<"Not Sorted";
    else cout<<"Sorted";
}

/*  Brute Force Approach
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int t = 0;
    for(int j = 0;j<n;j++)
    {
        for(int i = j+1;i<n;i++)
        {
            if(arr[i] < arr[j])
            {
                t++;
               break;
            }
        }
    }
    if(t) cout<<"Not Sorted\n";
    else cout<<"Sorted\n";
*/