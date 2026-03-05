#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

void insert(Node* root, int data)
{
    Node* prev = nullptr;
    while(root)
    {
        if(root -> val > data)
        {
            prev = root;
            root = root -> left;
        }
        else if(root -> val < data) 
        {
            prev = root;
            root = root -> right;
        }
    }
    if(prev -> val > data) prev -> left = new Node(data);
    else prev -> right = new Node(data);
}

Node* other_way(Node* root, int data)
{
    if(root == NULL) return new Node(data);
    Node* cur = root;
    while(true)
    {
        if(cur -> val <= data)
        {
            if(cur -> right != NULL) cur = cur -> right;
            else
            {
                cur -> right = new Node(data);
                break;
            }
        }
        else
        {
            if(cur -> left != NULL) cur = cur -> left;
            else
            {
                cur -> left = new Node(data);
                break;
            }
        }
    }
    return root;
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
    Node* root = new Node(4);
    root -> left = new Node(2);
    root -> right = new Node(7);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);

    // insert(root, 5);
    Node* newRoot = other_way(root, 5);

    inorder(newRoot);
}