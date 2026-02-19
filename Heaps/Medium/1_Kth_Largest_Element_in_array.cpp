#include <iostream>
using namespace std;

int bru_way(vector<int>& arr, int k)
{
    // It acts as a Min Heap <Type, COntainer(vector<Type>), greater<int>, less<int>>
    // greater <int> is for Min Heap 
    // less <int> is for Max Heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < k; i++) pq.push(arr[i]);

    for(int i = k; i < arr.size(); i++)
    {
        if(arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int randomIndex(int &left, int &right)
{
    int len = right - left + 1;
    return (rand() % len) + left;
}

int partitionAndReturnIndex(vector<int>& arr, int pivotIndex, int left, int right)
{
    int pivot = arr[pivotIndex];

    swap(arr[left], arr[pivotIndex]);

    int ind = left + 1;

    for(int i = left + 1; i<= right; i++)
    {
        if(arr[i] > pivot)
        {
            swap(arr[ind], arr[i]);

            ind++;
        }
    }

    swap(arr[left], arr[ind - 1]);

    return ind - 1;
}

int op_way(vector<int>& arr, int k)
{
    if(k > arr.size()) return -1;

    int left = 0, right = arr.size() - 1;

    while(true)
    {
        int pivotIndex = randomIndex(left, right);

        pivotIndex = partitionAndReturnIndex(arr, pivotIndex, left, right);

        if(pivotIndex == k - 1) return arr[pivotIndex];

        else if(pivotIndex > k - 1) right = pivotIndex - 1;
        else left = pivotIndex + 1;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    int ans = bru_way(arr, 2);

    cout<<ans<<endl;
}