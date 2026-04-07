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

vector<vector<string>> op_way(vector<vector<string>>& details)
{
    int n = details.size();

    DisjointSet ds(n);

    unordered_map<string, int> mapMailNode;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < details[i].size(); j++)
        {
            string mail = details[i][j];

            if(mapMailNode.find(mail) == mapMailNode.end())
                mapMailNode[mail] = i;
            else
                ds.unionBySize(i, mapMailNode[mail]);
        }
    }

    // group email at ultimate parent
    vector<vector<string>> mergedMail(n);
    for(auto it: mapMailNode)
    {
        string mail = it.first;
        int node = ds.findUParent(it.second);
        mergedMail[node].push_back(mail);
    }

    // prepare final merge result
    vector<vector<string>> ans;
    for(int i = 0; i < n; i++)
    {
        if(mergedMail[i].empty()) continue;

        vector<string> temp;
        temp.push_back(details[i][0]);

        for(auto& mail: mergedMail[i])
        {
            temp.push_back(mail);
        }
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    vector<vector<string>> ans = op_way(accounts);
    for(auto acc: ans)
    {
        cout<<acc[0]<<": ";
        for(int i = 1; i < acc.size(); i++)
        {
            cout<<acc[i]<<" ";
        }
        cout<<endl;
    }
}