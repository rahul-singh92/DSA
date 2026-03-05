#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

Node* findLastRight(Node* root)
{
    if(root -> right == NULL) return root;
    return findLastRight(root -> right);
}

Node* helper(Node* root)
{
    if(root -> left == NULL) return root -> right;
    else if(root -> right == NULL) return root -> left;

    Node* rightChild = root -> right;
    Node* lastRight = findLastRight(root -> left);
    lastRight -> right = rightChild;
    return root -> left;
}

Node* deleteNode(Node* root, int data)
{
    if(root == NULL) return nullptr;
    if(root -> val == data) return helper(root);

    Node* dummy = root;
    while(root)
    {
        if(root -> val > data)
        {
            if(root -> left != NULL && root -> left -> val == data)
            {
                root -> left = helper(root -> left);
                break;
            }
            else root = root -> left;
        }
        else
        {
            if(root -> right != NULL && root -> right -> val == data)
            {
                root -> right = helper(root -> right);
                break;
            }
            else root = root -> right;
        }
    }
    return dummy;
}

void inorder(Node* root)
{
    if(!root) return;

    inorder(root -> left);
    cout<<root -> val<<" ";
    inorder(root -> right);
}


int main()
{
    Node* root = new Node(5);
    root -> left = new Node(3);
    root -> right = new Node(6);
    root -> right -> right = new Node(7);
    root -> left -> left = new Node(2);
    root -> left -> right = new Node(4);

    Node* newRoot = deleteNode(root, 3);

    inorder(root);
}