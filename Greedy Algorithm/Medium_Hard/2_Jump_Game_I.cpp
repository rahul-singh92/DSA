#include <iostream>
using namespace std;

bool op_way(vector<int>& nums)
{
    int maxInd = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(i > maxInd)
        {
            return false;
        }

        maxInd = max(maxInd, i + nums[i]);
    }

    return true;
}

int main()
{
    vector<int> nums = {4, 3, 7, 1, 2};

    bool ans = op_way(nums);

    cout<<ans<<endl;
}