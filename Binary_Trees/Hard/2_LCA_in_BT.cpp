#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* op_way(Node* root, Node* p, Node* q)
{
    if(!root || root == p || root == q) return root;

    Node* left = op_way(root -> left, p, q);
    Node* right = op_way(root -> right, p, q);

    if(!left) return right;
    else if(!right) return left;
    else return root;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Node* p = root -> left;
    Node* q = root -> right;

    Node* lca = op_way(root, p, q);
    cout<<lca->data<<endl;
}