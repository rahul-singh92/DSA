#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> op_way(Node* root)
{
    vector<vector<int>> result;

    if(!root) return result;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty())
    {
        int size = q.size();

        vector<int> level(size);

        for(int i = 0; i < size; i++)
        {
            Node* node = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;

            level[index] = node -> data;

            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }

        leftToRight = !leftToRight;

        result.push_back(level);
    }

    return result;
}

int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(5);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(6);

    vector<vector<int>> ans = op_way(root);

    for(auto i: ans)
    {
        for(auto v: i) cout<<v<<" ";
        cout<<endl;
    }
}