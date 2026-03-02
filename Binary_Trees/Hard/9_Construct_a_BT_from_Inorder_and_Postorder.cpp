#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val(d), left{nullptr}, right{nullptr} {}
};

Node* buildTree(vector<int>& inorder, int inStart, int inEnd,
               vector<int>& postorder, int posStart, int postEnd, map<int, int>& inMap)
{
    if(inStart > inEnd || posStart > postEnd) return nullptr;

    Node* root = new Node(postorder[postEnd]);
    int inRoot = inMap[root -> val];
    int numsLeft = inRoot - inStart;

    root -> left = buildTree(inorder, inStart, inRoot - 1,
                             postorder, posStart, posStart + numsLeft - 1, inMap);
    root -> right = buildTree(inorder, inRoot + 1, inEnd,
                              postorder, posStart + numsLeft, postEnd - 1, inMap);
    return root;
}

Node* op_way(vector<int>& inorder, vector<int>& postorder)
{
    map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
    return buildTree(inorder, 0, inorder.size() - 1,
              postorder, 0, postorder.size() - 1, inMap);
}

void Inorder(Node* root)
{
    if(!root) return;

    Inorder(root -> left);
    cout<<root -> val<<" ";
    Inorder(root -> right);
}

int main()
{
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    Node* root = op_way(inorder, postorder);

    Inorder(root);
    cout<<endl;
}