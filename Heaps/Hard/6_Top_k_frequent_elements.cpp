#include <iostream>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    
    // Step 1: Count frequencies
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    // Step 2: Min heap (frequency, number)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > minHeap;

    // Step 3: Maintain heap of size k
    for (auto& p : freq) {
        minHeap.push({p.second, p.first});
        
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Step 4: Extract results
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

vector<int> op_way(vector<int>& arr, int k)
{
    unordered_map<int, int> freq;

    for(int i: arr) freq[i]++;

    int n = arr.size();
    vector<vector<int>> buckets(n + 1);

    for(auto& pair: freq)
    {
        int number = pair.first;
        int count = pair.second;
        buckets[count].push_back(number);
    }

    vector<int> result;
    for(int i = n; i >= 0 && result.size() < k; i--)
    {
        for(int n: buckets[i])
        {
            result.push_back(n);
            if(result.size() == k) break;
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    
    vector<int> ans = topKFrequent(arr, 2);

    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
}