#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap)
{
    if(preStart > preEnd || inStart > inEnd) return nullptr;

    Node* root = new Node(preorder[preStart]);

    int inRoot = inMap[root -> data];

    int numsLeft = inRoot - inStart;

    root -> left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                             inorder, inStart, inRoot - 1, inMap);
    root -> right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
                             inorder, inRoot + 1, inEnd, inMap);
    
    return root;
}

Node* op_way(vector<int>& preorder, vector<int>& inorder)
{
    map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}

void printInorder(Node* root) 
{
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node* root = op_way(preorder, inorder);

    printInorder(root);
    cout << endl;
}