#include <iostream>
using namespace std;

int op_way(int V, vector<vector<int>>& edges)
{
    vector<vector<int>> adj(V);
    for(auto &e: edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> visited(V, 0);

    int component = 0;
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            component++;

            //Start BFS
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(auto &nbr: adj[node])
                {
                    if(!visited[nbr])
                    {
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
        }
    }
    return component;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    int ans = op_way(V, edges);
    cout<<ans<<endl;
}