#include <iostream>
using namespace std;

struct Node
{
    Node* link[2] = {NULL};
    
    bool containKey(int bit)
    {
        return link[bit] != NULL;
    }

    void add(int bit, Node* node)
    {
        link[bit] = node;
    }

    Node* go(int i)
    {
        return link[i];
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
                int bit = (num >> i) & 1;

                if(!node -> containKey(bit))
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
                int bit = (num >> i) & 1;
                if(node -> containKey(1 - bit))
                {
                    maxXOR = maxXOR | (1 << i);
                    node = node -> go(1 - bit);
                }
                else 
                {
                    node = node -> go(bit);
                }
            }
            return maxXOR;
        }
};

int findMaxXOR(vector<int>& arr)
{
    Trie* trie = new Trie();

    for(int n: arr)
        trie -> insert(n);
    
    int maxi = 0;
    for(int n: arr)
    {
        maxi = max(maxi, trie -> getMaxXOR(n));
    }
    return maxi;
}

int main()
{
    vector<int> arr = {3, 9, 10, 5, 1};
    cout<<findMaxXOR(arr)<<endl;
}