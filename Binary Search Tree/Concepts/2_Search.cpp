#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

Node* searchBST(Node* root, int data)
{
    while(root != nullptr && root -> val != data)
    {
        if(root -> val < data) root = root -> right;
        else root = root -> left;
    }
    return root;
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Node* res = searchBST(root, 2);

    if(res) cout<<res -> val<<endl;
    else cout<<"Not found\n";
}