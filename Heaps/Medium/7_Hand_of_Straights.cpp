#include <iostream>
#include <map>
using namespace std;

bool op_way(vector<int>& arr, int n)
{
    if(arr.size() % n != 0) return false;

    map<int, int> freq;
    for(int c: arr)
    {
        freq[c]++;
    }

    auto it = freq.begin();

    while(it != freq.end())
    {
        if(it -> second == 0)
        {
            ++it;
            continue;
        }

        int start = it -> first;

        int count = it -> second;

        for(int i = 0; i < n; i++)
        {
            if(freq[start + i] < count) return false;

            freq[start + i] -= count;
        }
        ++it;
    }
    return true;
}

int main()
{
    vector<int> arr = {1,2,3,6,2,3,4,7,8};

    bool ans = op_way(arr, 3);

    cout<<ans<<endl;
}