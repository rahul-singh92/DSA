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

    int l = INT_MIN,sl = INT_MIN,s = INT_MAX,ss = INT_MAX;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] > l) 
        {
            sl = l;
            l = arr[i];
        }
        else if(arr[i] > sl && arr[i] != l)
        {
            sl = arr[i];
        }
        if(arr[i] < s)
        {
            ss = s;
            s = arr[i];
        }
        else if(arr[i] < ss && arr[i] != s)
        {
            ss = arr[i];
        }
    }
    if(n<2)
    {
        cout<<-1<<endl;
    }
    else cout<<"Second Largest Element is "<<sl<<endl;
    if(n<2) cout<<-1<<endl;
    else cout<<"Second Smallest Element is "<<ss<<endl;
    return 0;
}