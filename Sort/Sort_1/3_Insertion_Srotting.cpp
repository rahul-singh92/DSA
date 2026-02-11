#include <iostream>
using namespace std;

O(n^2)
void insertion_sort(vector<int>& arr)
{
    int n = arr.size();

    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--; 
        }

        arr[j+1] = key;
    }
}

int main()
{
    vector<int> arr = {7, 4, 1, 5, 3}; 
    insertion_sort(arr);

    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}