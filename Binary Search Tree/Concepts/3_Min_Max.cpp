#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

pair<int, int> searchBST(Node* root)
{
    if(root == nullptr) return {0, 0};
    
    Node* lef = root;
    Node* righ = root;
    while(lef -> left) lef = lef -> left;
    while(righ -> right) righ = righ -> right;

    return {lef -> val, righ -> val};
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    pair<int, int> res = searchBST(root);

    cout<<res.first<<" "<<res.second<<endl;
}