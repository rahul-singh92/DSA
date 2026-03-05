#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

void inOrder(Node* root, vector<int>& values)
{
    if(!root) return;
    inOrder(root -> left, values);
    values.push_back(root -> val);
    inOrder(root -> right, values);
}

vector<int> bru_way(Node* root, int k)
{
    vector<int> values;
    inOrder(root, values);

    return {values[k-1], values[values.size() - k]};
}

void Inorder(Node* root, int& k, int& result)
{
    if(root == nullptr) return;
    
    Inorder(root -> left, k, result);

    if(--k == 0)
    {
        result = root -> val;
        return;
    }

    Inorder(root -> right, k, result);
}

void reverse_inorder(Node* root, int& k, int& result)
{
    if(root == nullptr) return;
    reverse_inorder(root -> right, k, result);
    if(--k == 0)
    {
        result = root -> val;
        return;
    }
    reverse_inorder(root -> left, k, result);
}

int kthSmallest(Node* root, int k)
{
    int result = -1;
    Inorder(root, k, result);
    return result;
}

int kthLargest(Node* root, int k)
{
    int result = -1;
    reverse_inorder(root, k, result);
    return result;
}

vector<int> op_way(Node* root, int k)
{
    return {kthSmallest(root, k), kthLargest(root, k)};
}

int main()
{
    Node* root = new Node(3);
    root -> left = new Node(1);
    root -> right = new Node(2);
    root -> right = new Node(4);

    int k = 1;
    // vector<int> ans = bru_way(root, k);
    vector<int> ans = op_way(root, k);

    cout<<ans[0]<<" "<<ans[1]<<endl;
}