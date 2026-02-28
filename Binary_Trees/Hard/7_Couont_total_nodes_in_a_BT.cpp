#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d): data(d), left(NULL), right(NULL) {}
};

void inorder(Node* root, int& count)
{
    if(!root) return;

    count++;
    inorder(root -> left, count);
    inorder(root -> right, count);
}

int bru_way(Node* root)
{
    if(!root) return 0;

    int count = 0;
    inorder(root, count);
    return count;
}

int findHeightLeft(Node* node)
{
    int height = 0;
    while(node)
    {
        height++;
        node = node -> left;
    }
    return height;
}

int findHeightRight(Node* node)
{
    int height = 0;
    while(node)
    {
        height++;
        node = node -> right;
    }
    return height;
}



int op_way(Node* root)
{
    if(!root) return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if(lh == rh) return (1 << lh) - 1;

    return 1 + op_way(root -> left) + op_way(root -> right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    int ans = op_way(root);
    cout<<ans<<endl;
}