#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

int bru_way(Node* root)
{
    if(root == nullptr) return 0;

    int lh = bru_way(root -> left);
    int rh = bru_way(root -> right);

    return 1 + max(lh, rh);
}

int op_way(Node* root)
{
    if(root == nullptr) return 0;

    int lh = op_way(root -> left);
    
    if(lh == -1) return -1;

    int rh = op_way(root -> right);

    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return max(lh, rh) + 1;
}

int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(5);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(6);

    // int lt = bru_way(root -> left);
    // int rt = bru_way(root -> right);

    // int ans = abs(lt - rt);

    // cout<<((ans <= 1) ? "True" : "False")<<endl;


    int ans = op_way(root);
    cout<<((ans != -1) ? "True": "False")<<endl;
}