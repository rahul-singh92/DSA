#include <iostream>
using namespace std;

// O(n*log n)
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    
    while(i < j)
    {
        while(arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while(arr[j] >= pivot && j >= low + 1)
        {
            j--;
        }
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);

    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}