
#include <iostream>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void op_way(Node* root)
{
    if(!root) return;

    int child = 0;
    if(root -> left) child += root -> left -> val;
    if(root -> right) child += root -> right -> val;

    if(child >= root -> val) root -> val = child;
    else
    {
        if(root -> left) root -> left -> val = root -> val;
        else if(root -> right) root -> right -> val = root -> val;
    }

    op_way(root -> left);
    op_way(root -> right);

    int total = 0;
    if(root -> left) total += root -> left -> val;
    if(root -> right) total += root -> right -> val;

    if(root -> left or root -> right)
    {
        root -> val = total;
    }
}

void inOrderTraversal(Node* root)
{
    if(!root) return;

    inOrderTraversal(root -> left);
    cout<<root -> val<<" ";
    inOrderTraversal(root -> right);
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    op_way(root);

    inOrderTraversal(root);
    cout<<endl;
}
                            