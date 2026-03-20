#include <iostream>
using namespace std;

vector<int> op_way(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> adj(numCourses);

    vector<int> indegree(numCourses, 0);

    for(int i = 0; i < numCourses; i++)
    {
        int a = prerequisites[i][0], b = prerequisites[i][1];
        adj[b].push_back(a);
        indegree[a]++;
    }

    queue<int> q;

    for(int i = 0 ; i < numCourses; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> order;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for(int nei: adj[node])
        {
            indegree[nei]--;
            if(indegree[nei] == 0) q.push(nei);
        }
    }

    if(order.size() == numCourses) return order;
    return {};
}

int main()
{
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourses = 4;

    vector<int> ans = op_way(numCourses, prerequisites);
    for(auto i: ans) cout<<i<<" ";
}