#include <iostream>
using namespace std;

void selection_sort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 0; i < n - 1; i++)
    {
        int cur = arr[i];
        int mini = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[mini]) mini = j;
        }
        if(mini != i)
        {
            arr[mini] = arr[mini] ^ arr[i];
            arr[i] = arr[i] ^ arr[mini];
            arr[mini] = arr[mini] ^ arr[i];
        }
    }
}

int main()
{
    vector<int> arr = {13,46,24,52,20,9};
    selection_sort(arr);

    for(auto i : arr) cout<<i<<" ";
    cout<<endl;
}