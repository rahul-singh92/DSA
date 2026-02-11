#include <iostream>
using namespace std;

void bubble_sort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for(int j = 0; j <= i - 1; j++)
        {
            if(arr[j] > arr[j+1]) 
            {
                swap(arr[j], arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
    }
}

int main()
{
    vector<int> arr = {5,4,3,2,1};
    bubble_sort(arr);
    for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}