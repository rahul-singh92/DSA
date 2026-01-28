#include <iostream>
#include <set>
using namespace std;

void findSubset(int ind, vector<int>& nums, vector<int>& ds, set<vector<int>>& result)
{
    if(ind == nums.size())
    {
        result.insert(ds);
        return;
    }

    ds.push_back(nums[ind]);
    findSubset(ind + 1, nums, ds, result);
    ds.pop_back();

    findSubset(ind + 1, nums, ds, result);
}

//Find all possible subset and put in set to remove duplicated
vector<vector<int>> Brute_way(vector<int>& nums)
{
    set<vector<int>> result;
    vector<int> ds;

    sort(nums.begin(), nums.end());
    
    findSubset(0, nums, ds, result);

    vector<vector<int>> ans(result.begin(), result.end());
    return ans;
}


void backtrack(int start, vector<int>& nums, vector<int>& ds, vector<vector<int>>& result)
{
    result.push_back(ds);

    for(int i = start; i < nums.size(); i++)
    {
        //skip if next and current are same
        if(i > start && nums[i] == nums[i-1]) continue;

        ds.push_back(nums[i]);

        backtrack(i + 1, nums, ds, result);

        ds.pop_back();
    }
}

//Sort before and see before if it is duplicate and then skip it
vector<vector<int>> Opt_way(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    vector<int> ds;

    backtrack(0, nums, ds, result);

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = Opt_way(nums);

    for(auto i : ans)
    {
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
    }
}