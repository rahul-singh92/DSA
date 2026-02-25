#include <iostream>
using namespace std;

int bru_way(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    int maxValid = 0;

    for (int mask = 0; mask < (1 << n); ++mask)
    {
        vector<vector<int>> subset;

        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
                subset.push_back(intervals[i]);
        }

        sort(subset.begin(), subset.end());

        bool valid = true;
        for (int i = 1; i < subset.size(); ++i)
        {
            if (subset[i][0] < subset[i - 1][1])
            {
                valid = false;
                break;
            }
        }

        if (valid)
            maxValid = max(maxValid, (int)subset.size());
    }

    return n - maxValid;
}

int op_way(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    }); 

    int count = 0;

    int prevEnd = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0] < prevEnd)
        {
            count++;
        }
        else prevEnd = intervals[i][1];
    }
    return count;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int ans = op_way(intervals);
    cout<<ans<<endl;
    return 0;
}
