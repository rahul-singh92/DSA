#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node* root)
{
    return !root -> left && !root -> right;
}

void addLeftBoundary(Node* node, vector<int>& res)
{
    Node* curr = node -> left;

    while(curr)
    {
        if(!isLeaf(curr)) res.push_back(curr -> data);

        if(curr -> left) curr = curr -> left;
        else curr = curr -> right;
    }
}

void addRightBoundary(Node* node, vector<int>& res)
{
    Node* curr = node -> right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr)) temp.push_back(curr -> data);

        if(curr -> right) curr = curr -> right;
        else curr = curr -> left;
    }

    for(int i = temp.size() - 1; i >= 0; i--) res.push_back(temp[i]);
}

void addLeaves(Node* node, vector<int>& res)
{
    if(isLeaf(node))
    {
        res.push_back(node -> data);
        return;
    }

    if(node -> left) addLeaves(node -> left, res);

    if(node -> right) addLeaves(node -> right, res);
}

vector<int> op_way(Node* node)
{
    vector<int> res;
    if(!node) return res;

    if(!isLeaf(node)) res.push_back(node -> data);

    addLeftBoundary(node, res);
    addLeaves(node, res);
    addRightBoundary(node, res);

    return res;
}

int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(5);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(6);

    vector<int> ans = op_way(root);

    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}