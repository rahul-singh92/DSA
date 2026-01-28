#include <iostream>
using namespace std;

void findAll(int n, int last, vector<int>& ds,int k, vector<vector<int>>& result)
{
    if(n == 0 && ds.size() == k)
    {
        result.push_back(ds);
        return;
    }
    if(n <= 0 || ds.size() > k) return;

    for(int i = last; i <= 9; i++)
    {
        if(i <= n)
        {
            ds.push_back(i);
            findAll(n - i, i + 1, ds, k, result);
            ds.pop_back();
        }
        else
        {
            break;
        }
    }
}

vector<vector<int>> opt_way(int n, int k)
{
    vector<vector<int>> result;
    vector<int> ds;

    findAll(n, 1, ds, k, result);

    return result;
}

int main()
{
    int n = 9, k = 3;
    vector<vector<int>> ans = opt_way(n, k);

    for(auto i : ans)
    {
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
    }
}