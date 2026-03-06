#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

Node* convert_bst(vector<int>& a, int& i, int bound)
{
    if(i == a.size() || a[i] > bound) return nullptr;
    Node* root = new Node(a[i++]);
    root -> left = convert_bst(a, i, root -> val);
    root -> right = convert_bst(a, i, bound);
    return root;
}

Node* op_way(vector<int>& preorder)
{
    int i = 0;
    return convert_bst(preorder, i, INT_MAX);
}

Node* insert(Node* root, int value)
{
    if(root == nullptr) return new Node(value);
    if(value < root -> val)
    {
        root -> left = insert(root -> left, value);
    }
    else root -> right = insert(root -> right, value);

    return root;
}

Node* bru_way(vector<int>& preorder)
{
    Node* root = nullptr;
    for(int i = 0; i < preorder.size(); i++)
    {
        root = insert(root, preorder[i]);
    }
    return root;
}

Node* buildTree(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap)
{
    if(preStart > preEnd || inStart > inEnd) return nullptr;

    Node* root = new Node(preorder[preStart]);

    int inRoot = inMap[root -> val];

    int numsLeft = inRoot - inStart;

    root -> left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                             inorder, inStart, inRoot - 1, inMap);
    root -> right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
                             inorder, inRoot + 1, inEnd, inMap);
    
    return root;
}

Node* bet_way(vector<int>& preorder)
{
    vector<int> inorder(preorder);
    sort(inorder.begin(), inorder.end());
    
    map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}

void PreOrder(Node* root)
{
    if(!root) return;
    cout<<root -> val<<" ";
    PreOrder(root -> left);
    PreOrder(root -> right);
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Node* root = bet_way(preorder);

    PreOrder(root);
}