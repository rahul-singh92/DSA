#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

void bru_way(Node* root, vector<int>& bst)
{
    if(!root) return;
    bru_way(root -> left, bst);
    bst.push_back(root -> val);
    bru_way(root -> right, bst);
}

bool isValidBST(Node* root, long minVal, long maxVal)
{
    if(!root) return true;
    if(root -> val >= maxVal || root -> val <= minVal) return false;
    return isValidBST(root -> left, minVal, root -> val) &&
           isValidBST(root -> right, root -> val, maxVal);
}

bool op_way(Node* root)
{
    return isValidBST(root, INT_MIN, INT_MAX); 
}

int main()
{
    Node* root = new Node(3);
    root -> left = new Node(1);
    root -> right = new Node(2);
    root -> right = new Node(4);

    vector<int> bst;
    // bru_way(root, bst);
    bool ans = op_way(root);
    // cout<<is_sorted(bst.begin(), bst.end());
    cout<<ans<<endl;
}