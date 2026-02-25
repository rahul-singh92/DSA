#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void postorder(Node* root, vector<int>& arr)
{
    if(root == nullptr) return;

    postorder(root -> left, arr);
    postorder(root -> right, arr);
    arr.push_back(root -> data);
}

vector<int> postOrder(Node* root)
{
    vector<int> arr;
    postorder(root, arr);
    return arr;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    for(int val : result) 
    {
        cout << val << " ";
    }
    cout << endl;
}
