#include <iostream>
using namespace std;

vector<int> op_way(int V, vector<vector<int>>& adj)
{
    vector<vector<int>> adjRev(V);

    vector<int> indegree(V, 0);

    for(int i = 0; i < V; i++)
    {
        for(auto& it: adj[i])
        {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;

    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for(auto it: adjRev[node])
        {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main()
{
    vector<vector<int>> adj = {
        {1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}
    };
    int V = 12;

    vector<int> ans = op_way(V, adj);
    for(auto i: ans) cout<<i<<" ";
}