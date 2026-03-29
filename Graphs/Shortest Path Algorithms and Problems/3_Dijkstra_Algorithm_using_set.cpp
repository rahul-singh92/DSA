#include <iostream>
#include <set>
using namespace std;

vector<int> dijkstra(int V, vector<vector<vector<int>>>& adj, int S)
{
    // for storing the node as pair {dist, node}
    // where dist is the distance from source to node
    // It stores the nodes in ascending order of the distances
    set<pair<int, int>> st;

    vector<int> dist(V, 1e9);

    st.insert({0, S});

    while(!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it: adj[node])
        {
            int adjNode = it[0]; // adjacent node
            int edgW = it[1]; // edge weight

            if(dis + edgW < dist[adjNode])
            {
                // Erase the previously entry of the adjacent node 
                // if it was visited previously with a larger cost
                if(dist[adjNode] != 1e9) st.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + edgW;

                // Innsert with updated distance
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    int V = 3, E = 3, S = 2; // number of vertices, edges and source node
    vector<vector<vector<int>>> adj(V);

    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> ans = dijkstra(V, adj, S);

    for(int i = 0; i < V; i++)
    {
        cout<<ans[i]<<" ";
    }
}