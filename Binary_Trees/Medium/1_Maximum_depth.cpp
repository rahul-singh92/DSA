#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

int dep(Node* root)
{
    if(root == nullptr) return 0;

    int lh = dep(root -> left);
    int rh = dep(root -> right);

    return 1 + max(lh, rh);
}

int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(5);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(6);
    root -> right -> left -> left = new Node(5);

    int ans = dep(root);

    cout<<ans<<endl;
}