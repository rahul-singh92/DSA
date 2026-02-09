#include <iostream>
using namespace std;

vector<int> num_great_next(vector<int>& arr)
{
    vector<int> res;
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        int c = 0;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] > arr[i]) c++;
        }
        res.push_back((c == 0) ? -1 : c);
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    vector<int> res = num_great_next(arr);

    for(auto i : res) cout<<i<<" ";
}