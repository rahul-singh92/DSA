#include <iostream>
using namespace std;

vector<vector<int>> op_way(vector<vector<int>>& interval, vector<int> newInterval)
{
    vector<vector<int>> result;
    int n = interval.size();
    int i = 0;
    while(i < n && interval[i][1] < newInterval[0])
    {
        result.push_back(interval[i]);
        i++;
    }

    while(i < n && interval[i][0] < newInterval[1])
    {
        newInterval[0] = min(newInterval[0], interval[i][0]);
        newInterval[1] = max(newInterval[1], interval[i][1]);
        i++; 
    }
    result.push_back(newInterval);

    while(i < n)
    {
        result.push_back(interval[i]);
        i++;
    }

    return result;
}

int main()
{
    vector<vector<int>> interval = {{1, 3}, {6, 9}};

    vector<vector<int>> ans = op_way(interval, {2, 5});

    for(auto i: ans)
    {
        cout<<i[0] <<" "<<i[1]<<endl;
    }
}