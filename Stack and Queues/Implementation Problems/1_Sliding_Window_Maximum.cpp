#include <iostream>
using namespace std;

// O(n^2)
vector<int> bru_way(vector<int>& arr, int k)
{
    vector<int> result;

    for(int i = 0; i <= arr.size() - k; i++)
    {
        int maxVal = arr[i];
        for(int j = i; j < i + k; j++)
        {
            maxVal = max(maxVal, arr[j]);
        }
        result.push_back(maxVal);
    }
    return result;
}

//O(2*n). using dequeue
vector<int> op_way(vector<int>& arr, int k)
{
    deque<int> dq;
    vector<int> result;

    for(int i = 0; i < arr.size(); i++)
    {
        //Remove element from the front if they are out of windows range
        if(!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        // Once the window is completed, add front elemettn to the result;
        if(i >= k - 1)
        {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;
    vector<int> ans = op_way(arr, k);

    for(auto i : ans) cout<<i<<" ";
}
