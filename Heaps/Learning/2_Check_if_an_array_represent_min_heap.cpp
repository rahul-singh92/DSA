#include <iostream>
using namespace std;

bool min_heap(vector<int>& arr)
{
    for(int i = 0; i <= (arr.size() / 2) - 1; i++)
    {
        int left = 2*i+1;
        if(left < arr.size() && arr[left] < arr[i])
        {
            return false;
        }

        int right = 2*i+2;
        if(right < arr.size() && arr[right] < arr[i]) return false;
    }
    return true;
}

int main()
{
    vector<int> arr = {10, 20, 30, 25, 15};
    bool ans = min_heap(arr);

    cout<<ans<<endl;
}