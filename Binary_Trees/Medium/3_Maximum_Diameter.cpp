#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

int cal(Node* root, int& diameter)
{
    if(root == nullptr) return 0;

    int lh = cal(root -> left, diameter);
    int rh = cal(root -> right, diameter);

    diameter = max(diameter, 1 + lh + rh);

    return 1 + max(lh, rh);
}

int op_way(Node* root)
{
    int diameter = 0;
    cal(root, diameter);
    return diameter;
}

int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(5);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(6);

    int ans = op_way(root);

    cout<<ans<<endl;
}