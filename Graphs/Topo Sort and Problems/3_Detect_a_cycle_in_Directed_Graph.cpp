#include <iostream>
using namespace std;

bool op_way(int V, vector<vector<int>>& adj)
{
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++)
    {
        for(auto v: adj[i])
        {
            indegree[v]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for(int neghbour: adj[node])
        {
            indegree[neghbour]--;
            if(indegree[neghbour] == 0)
            {
                q.push(neghbour);
            }
        }
    }
    return count != V;
}

int main()
{
    int V = 4;
    vector<vector<int>> adj = {
        {1}, {2}, {3}, {1}
    };

    bool ans = op_way(V, adj);
    cout<<ans<<endl;
}