#include <iostream>
#include <set>
using namespace std;

class DisjointSet
{
    public:
    vector<int> rank, parent, size;
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

vector<int> delRow = {-1, 0, 1, 0};
vector<int> delCol = {0, 1, 0, -1};

bool isValid(int newRow, int newCol, int n)
{
    if(newRow < 0 || newRow >= n) return false;
    if(newCol < 0 || newCol >= n) return false;
    return true;
}

void addInitialIsland(vector<vector<int>>& grid, DisjointSet& ds, int n)
{
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            if(grid[row][col] == 0) continue;

            for(int i = 0; i < 4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1)
                {
                    int node = row * n + col;
                    int adjNode = newRow * n + newCol;

                    ds.unionBySize(node, adjNode);
                }
            }
        }
    }
}

int op_way(vector<vector<int>>& grid)
{
    int n = grid.size();
    DisjointSet ds(n*n);

    addInitialIsland(grid, ds, n);
    int ans = 0;

    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            if(grid[row][col] == 1) continue;

            // to store the ultimate parent of neighbouring islands
            set<int> components;

            for(int ind = 0; ind < 4; ind++)
            {
                int newRow = row + delRow[ind];
                int newCol = col + delCol[ind];

                if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1)
                {
                    int nodeNumber = newRow * n + newCol;
                    components.insert(ds.findUParent(nodeNumber));
                }
            }

            int sizeTotal = 0;
            for(auto it: components)
            {
                sizeTotal += ds.size[it];
            }
            ans = max(ans, sizeTotal + 1);
        }
    }
    for(int cellNo = 0; cellNo < n * n; cellNo++)
    {
        ans = max(ans, ds.size[ds.findUParent(cellNo)]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}  
    };
    
    int ans = op_way(grid);
    cout<<ans<<endl;
}