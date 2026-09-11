#include <iostream>
using namespace std;

struct Node
{
    Node* link[2] = {NULL};

    bool containsKey(int bit)
    {
        return link[bit] != NULL;
    }

    void add(int bit, Node* node)
    {
        link[bit] = node;
    }

    Node* go(int bit)
    {
        return link[bit];
    }
};

class Trie
{
    private:
        Node* root;
    
    public:
        Trie()
        {
            root = new Node();
        }

        void insert(int num)
        {
            Node* node = root;

            for(int i = 31; i >= 0; i--)
            {
                int bit = (num>>i)&1;
                if(!node -> containsKey(bit))
                {
                    node -> add(bit, new Node());
                }
                node = node -> go(bit);
            }
        }

        int getMaxXOR(int num)
        {
            Node* node = root;
            int maxXOR = 0;

            for(int i = 31; i >= 0; i--)
            {
                int bit = (num>>i) & 1;
                if(node -> containsKey(1 - bit))
                {
                    maxXOR = maxXOR | (1 << i);
                    node = node -> go(1 - bit);
                }
                else node = node -> go(bit);
            }
            return maxXOR;
        }
};

vector<int> maxXorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int>>> q;

    for(int i = 0; i < queries.size(); i++)
    {
        q.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(q.begin(), q.end());

    vector<int> ans(queries.size(), 0);

    Trie* trie = new Trie();

    int ind = 0;
    for(int i = 0; i < queries.size(); i++)
    {
        int ai = q[i].first;
        int xi = q[i].second.first;
        int qInd = q[i].second.second;

        while(ind < arr.size() && arr[ind] <= ai)
        {
            trie -> insert(arr[ind++]);
        }
        if(ind == 0) ans[qInd] = -1;
        else ans[qInd] = trie -> getMaxXOR(xi);
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 10, 5, 25, 2, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {3, 3}};

    vector<int> ans = maxXorQueries(arr, queries);
    for(auto i: ans) cout<<i<<endl;
}