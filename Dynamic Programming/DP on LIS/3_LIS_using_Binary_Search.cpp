#include <iostream>
using namespace std;

int lis(vector<int>& arr)
{
    int n = arr.size();

    vector<int> temp;
    temp.push_back(arr[0]);

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > temp.back())
            temp.push_back(arr[i]);
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    int ans = lis(arr);
    cout<<ans<<endl;
}