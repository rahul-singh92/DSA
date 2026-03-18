#include <iostream>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st)
{
    visited[node] = 1;

    for(auto it: adj[node])
    {
        if(!visited[it]) dfs(it, adj, visited, st);
    }

    st.push(node);
}

vector<int> op_way(int V, vector<vector<int>>& adj)
{
    vector<int> visited(V, 0);

    stack<int> st;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i]) dfs(i, adj, visited, st);
    }

    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()
{
    int V = 6, E = 6;

    vector<vector<int>> adj(V);

    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    vector<int> ans = op_way(V, adj);

    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}