#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

Node* op_way(Node* root, int p, int q)
{
    if(!root) return nullptr;
    int cur = root -> val;
    if(cur < p && cur < q)
    {
        return op_way(root -> right, p, q);
    }
    if(cur > p && cur > q)
    {
        return op_way(root -> left, p, q);
    }
    return root;
}

int main()
{
    Node* root = new Node(3);
    root -> left = new Node(1);
    root -> right = new Node(7);
    root -> right -> right = new Node(9);
    root -> right -> left = new Node(6);

    Node* ans = op_way(root, 1, 9);
    cout<<ans -> val;
}