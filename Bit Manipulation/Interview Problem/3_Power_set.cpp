#include <iostream>
using namespace std;

int main()
{
    int nums[] = {1, 2, 3};
    int n = 3;

    vector<vector<int>> ans;
    for(int i = 0; i < (1 << n); i++)
    {
        vector<int> list;
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j)) list.push_back(nums[j]);
        }
        ans.push_back(list);
    }
    
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}