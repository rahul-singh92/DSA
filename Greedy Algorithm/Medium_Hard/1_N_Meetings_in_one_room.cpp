#include <iostream>
using namespace std;

vector<int> op_way(vector<int>& start, vector<int>& end)
{
    // store meeting as (end, start, index)   
    vector<tuple<int, int, int>> meetings;

    for(int i = 0; i< start.size(); i++)
    {
        meetings.push_back({end[i], start[i], i+1});
    }

    sort(meetings.begin(), meetings.end());

    vector<int> result;
    int lastEnd = -1;

    for(auto& m: meetings)
    {
        int e = get<0>(m);
        int s = get<1>(m);
        int idx = get<2>(m);

        if(s > lastEnd)
        {
            result.push_back(idx);
            lastEnd = e;
        }
    }
    return result;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<int> ans = op_way(start, end);
    for(int i: ans) cout<<i<<" ";
}