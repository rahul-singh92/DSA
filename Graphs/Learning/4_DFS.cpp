#include <iostream>
using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result)
{
    visited[v] = 1;
    result.push_back(v);
    for(int u: adj[v])
    {
        if(!visited[u]) dfs(u, adj, visited, result);
    }
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<int> visited(V, 0);
    vector<int> result;
    dfs(0, adj, visited, result);

    for(int x: result) cout<<x<<" ";
}