#include <iostream>
using namespace std;

vector<int> bfs(int V, vector<vector<int>>& adj)
{
    vector<int> visited(V, 0);
    visited[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> result;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(auto& i: adj[node])
        {
            if(!visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return result;
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

    vector<int> result = bfs(V, adj);

    for(int i: result) cout<<i<<" ";
}