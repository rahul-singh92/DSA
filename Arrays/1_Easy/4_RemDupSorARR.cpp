#include <iostream>
#include <set>
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
    int i = 0;
    for(int j = 0;j<n;j++)
    {
        if(arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    for(int j = 0;j<i+1;j++)
    {
        cout<<arr[j]<<" ";
    }
}

/*  Brute Force Approach
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    set <int> st;
    for(int i = 0;i<n;i++)
    {
        st.insert(arr[i]);
    }
    int index = 0;
    for(auto it:st)
    {
        arr[index++] = it;
    }

    for(int i = 0;i<index;i++)
    {
        cout<<arr[i]<<" ";
    }
*/