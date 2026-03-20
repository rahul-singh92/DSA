#include <iostream>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>>& adj)
{
    vector<int> indegree(V, 0);

    for(int i = 0; i < V; i++)
    {
        for(auto neigh: adj[i])
        {
            indegree[neigh]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> topo;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto nei: adj[node])
        {
            indegree[nei]--;
            if(indegree[nei] == 0) q.push(nei);
        }
    }
    return topo;
}

string op_way(vector<string>& dict, int N, int K)
{
    vector<vector<int>> adj(K);

    for(int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());

        for(int ptr = 0; ptr < len; ptr++)
        {
            if(s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(K, adj);

    string ans = "";
    for(auto node: topo)
    {
        ans += char(node + 'a');
    }

    return ans;
}

int main()
{
    int N = 5, K = 4;
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    string ans = op_way(dict, N, K);
    for(auto ch: ans) cout<<ch<<" ";
}