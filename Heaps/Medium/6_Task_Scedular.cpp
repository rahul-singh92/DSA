#include <iostream>
using namespace std;

int op_way(vector<char>& arr, int n)
{
    unordered_map<char, int> freq;

    for(char c: arr)
    {
        freq[c]++;
    }

    priority_queue<int> maxHeap;
    for(auto& entry: freq)
    {
        maxHeap.push(entry.second);
    }

    int time = 0;

    while(!maxHeap.empty())
    {
        vector<int> temp;
        int cycle = n + 1;
        int i = 0;

        while(i < cycle && !maxHeap.empty())
        {
            int cnt = maxHeap.top();
            maxHeap.pop();

            cnt--;

            if(cnt > 0)
            {
                temp.push_back(cnt);
            }

            time++;

            i++;
        }

        for(int val: temp)
        {
            maxHeap.push(val);
        }

        if(maxHeap.empty()) break;

        time += (cycle - i);
    }

    return time;
}

int main()
{
    vector<char> arr = {'A','A','A','B','B','B'};
    
    int ans = op_way(arr, 2);

    cout<<ans<<endl;
}