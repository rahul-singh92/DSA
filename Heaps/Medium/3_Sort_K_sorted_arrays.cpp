#include <iostream>
using namespace std;

vector<int> bru_way(vector<int>& arr, int k)
{
    sort(arr.begin(), arr.end());

    return arr;
}

vector<int> op_way(vector<int>& arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    vector<int> result;

    for(int i = 0; i <= k && i < arr.size(); i++) 
        minHeap.push(arr[i]);
    
    for(int i = k + 1; i < arr.size(); i++)
    {
        result.push_back(minHeap.top());
        minHeap.pop();

        minHeap.push(arr[i]);
    }

    while(!minHeap.empty())
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};

    vector<int> ans = op_way(arr, 3);

    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
}