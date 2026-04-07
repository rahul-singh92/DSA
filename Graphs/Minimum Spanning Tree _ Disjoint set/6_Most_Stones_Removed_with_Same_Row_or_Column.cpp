#include <iostream>
#include <unordered_set>
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
                size[i] = i;
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

int op_way(vector<vector<int>>& stones)
{
    int maxRow = 0, maxCol = 0;
    for(auto it: stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNode;
    for(auto it: stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1; // adding so that for column it count like 1 2 3 then for col 4 5 6 
        ds.unionBySize(nodeRow, nodeCol);
        stoneNode[nodeRow] = 1;
        stoneNode[nodeCol] = 1;
    }

    int cnt = 0;
    for(auto it: stoneNode)
    {
        if(ds.findUParent(it.first) == it.first)
        {
            cnt++;
        }
    }
    return stones.size() - cnt;
}

int main()
{
    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };
    int ans = op_way(stones);
    cout<<ans<<endl;
}