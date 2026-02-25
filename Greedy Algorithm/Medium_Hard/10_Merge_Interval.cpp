#include <iostream>
using namespace std;

vector<vector<int>> bru_way(vector<vector<int>>& interval)
{
    int n = interval.size();

    vector<vector<int>> res;

    sort(interval.begin(), interval.end());

    for(int i = 0; i< n; )
    {
        int start = interval[i][0]; 
        int end = interval[i][1];

        int j = i + 1;
        while(j < n && interval[j][0] < end)
        {
            end = max(end, interval[j][1]);
            j++;
        }

        res.push_back({start, end});

        i = j;
    }
    return res;
}

vector<vector<int>> op_way(vector<vector<int>>& interval)
{
    sort(interval.begin(), interval.end());

    vector<vector<int>> ans;

    for(auto i: interval)
    {
        if(ans.empty() || ans.back()[1] < i[0])
        {
            ans.push_back(i);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], i[1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> interval = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans = op_way(interval);

    for(auto i: ans) cout<<i[0]<<" "<<i[1]<<endl;
}