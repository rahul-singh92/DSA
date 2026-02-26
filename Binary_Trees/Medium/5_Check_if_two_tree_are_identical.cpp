#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

int op_way(Node* node1, Node* node2)
{
    if(node1 == nullptr && node2 == nullptr) return true;

    if(node1 == NULL || node2 == NULL) return false;

    return ((node1 -> data == node2 -> data) && op_way(node1 -> left, node2 -> left) && op_way(node1 -> right, node2 -> right));
}

int main()
{
    Node* root1 = new Node(1);
    root1 -> left = new Node(2);
    root1 -> right = new Node(3);
    root1 -> left -> left = new Node(4);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    int ans = op_way(root1, root2);

    cout<<ans<<endl;
}