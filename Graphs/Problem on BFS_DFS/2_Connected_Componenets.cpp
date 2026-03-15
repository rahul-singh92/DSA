#include <iostream>
using namespace std;

int op_way(int V, vector<vector<int>>& edges)
{
    vector<vector<int>> adjList(V);
    for(auto& e: edges)
    {
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }

    vector<int> visited(V, 0);

    int components = 0;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            components++;

            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(auto& nbr: adjList[node])
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
    return components;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    int ans = op_way(V, edges);
    cout<<ans<<endl;
}