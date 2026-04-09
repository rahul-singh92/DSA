#include <iostream>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0; i <= n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUParent(int node)
        {
            if(node == parent[node])
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionBySize(int u, int v)
        {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

bool isValid(int adjr, int adjc, int n, int m)
{
    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
}

vector<int> op_way(int n, int m, vector<vector<int>>& operators)
{
    DisjointSet ds(n*m);
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;
    vector<int> ans;

    for(auto it: operators)
    {
        int row = it[0], col = it[1];

        // skip if already a land before the operation
        if(vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        for(int ind = 0; ind < 4; ind++)
        {
            int adjr = row + dr[ind], adjc = col + dc[ind];
            if(isValid(adjr, adjc, n, m))
            {
                if(vis[adjr][adjc] == 1)
                {
                    int nodeNo = row * m + col;
                    int adjNode = adjr * m + adjc;
                    if(ds.findUParent(nodeNo) != ds.findUParent(adjNode))
                    {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNode);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main()
{
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

    vector<int> ans = op_way(n, m, operators);

    for(auto i: ans)
    {
        cout<<i<<" ";
    }
}