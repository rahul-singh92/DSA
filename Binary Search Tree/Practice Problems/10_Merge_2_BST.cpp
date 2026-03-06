#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

void traverse(Node* root, vector<int>& ans)
{
    if(!root) return;
    traverse(root -> left, ans);
    ans.push_back(root -> val);
    traverse(root -> right, ans);
}

vector<int> bru_way(Node* root1, Node* root2)
{
    vector<int> ans;
    traverse(root1, ans);
    traverse(root2, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

vector<int> mergeArr(vector<int>& arr1, vector<int>& arr2)
{
    vector<int> merged;
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j]) merged.push_back(arr1[i++]);
        else merged.push_back(arr2[j++]);
    }

    while(i < arr1.size()) merged.push_back(arr1[i++]);
    while(j < arr1.size()) merged.push_back(arr2[j++]);
    return merged;
}

void inOrder(Node* root, vector<int>& arr)
{
    if(!root) return;
    inOrder(root -> left, arr);
    arr.push_back(root -> val);
    inOrder(root -> right, arr);
}

vector<int> op_way(Node* root1, Node* root2)
{
    vector<int> arr1, arr2;
    inOrder(root1, arr1);
    inOrder(root2, arr2);
    return mergeArr(arr1, arr2);
}

int main()
{
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(3);
    root2->left = new Node(0);
    root2->right = new Node(5);

    // vector<int> ans = bru_way(root1, root2);
    vector<int> ans = op_way(root1, root2);
    for(auto i: ans) cout<<i<<" ";
}