#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isSymmetricUtil(Node* root1, Node* root2)
{
    if(root1 == nullptr || root2 == nullptr) return root1 == root2;

    return (root1 -> data == root2 -> data)
            && isSymmetricUtil(root1 -> left, root2 -> right)
            && isSymmetricUtil(root1 -> right, root2 -> left);
}

bool isSymmetric(Node* root)
{
    if(!root) return true;

    return isSymmetricUtil(root -> left, root -> right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    bool res = isSymmetric(root);
    cout<<((res == true)? "True": "False");
}