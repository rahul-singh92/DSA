#include <iostream>
#include <unordered_set>
using namespace std;

class DSU
{
    vector<int> parent, rank;
    public:
        DSU(int n)
        {
            parent.resize(n+1);
            rank.resize(n+1, 0);
            for(int i = 0; i <= n; i++)
            {
                parent[i] = i;
            }
        }

        int find(int node)
        {
            if(node == parent[node])
                return node;
            return parent[node] = find(parent[node]);
        }

        void unite(int x, int y)
        {
            int ulp_x = find(x);
            int ulp_y = find(y);
            
            if(ulp_x == ulp_y) return;

            if(rank[ulp_x] < rank[ulp_y])
            {
                parent[ulp_x] = ulp_y;
            }
            else if(rank[ulp_x] > rank[ulp_y])
            {
                parent[ulp_y] = ulp_x;
            }
            else 
            {
                parent[ulp_y] = ulp_x;
                rank[ulp_x]++;
            }
        }
};

int op_way(int n, vector<vector<int>>& connection)
{
    // if edges are less than n - 1 we cant connect
    if(connection.size() < n - 1) return -1;

    DSU dsu(n);

    for(auto& edge: connection)
    {
        dsu.unite(edge[0], edge[1]);
    }

    unordered_set<int> component;
    for(int i = 0; i < n; i++)
    {
        component.insert(dsu.find(i));
    }

    return component.size() - 1;
}

int main()
{
    int n = 6;
    vector<vector<int>> connection = {{0,1}, {0,2}, {0,3}, {1,2}, {1,3}};
    int ans = op_way(n, connection);
    cout<<ans<<endl;
}