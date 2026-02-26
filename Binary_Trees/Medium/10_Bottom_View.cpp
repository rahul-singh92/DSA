#include <iostream>
#include <map>
#include <set>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> op_way(Node* root)
{
    vector<int> ans;

    if(root == nullptr) return ans;

    map<int, int> mpp;

    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        Node* node = p.first;
        int line = p.second;

        mpp[line] = node -> data;

        if(node -> left) q.push({node -> left, line - 1});

        if(node -> right) q.push({node -> right, line + 1});
    }

    for(auto i: mpp) ans.push_back(i.second);
    
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<int> ans = op_way(root);

    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
