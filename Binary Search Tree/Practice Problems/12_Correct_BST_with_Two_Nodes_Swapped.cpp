#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

void inOrder(Node* root, vector<int>& inorder)
{
    if(!root) return;
    inOrder(root -> left, inorder);
    inorder.push_back(root -> val);
    inOrder(root -> right, inorder);
}

void correctBST(Node* root, vector<int>& inorder, int& i)
{
    if(!root) return;

    correctBST(root -> left, inorder,i);
    root -> val = inorder[i++];
    correctBST(root -> right, inorder,i);
}

void bru_way(Node* root)
{
    vector<int> inorder;
    inOrder(root, inorder);
    sort(inorder.begin(), inorder.end());
    int i = 0;
    correctBST(root, inorder, i);
}

void inOrderOpWay(Node* root, Node*& prev, Node*& first, Node*& mid, Node*& last)
{
    if(!root) return;

    inOrderOpWay(root -> left, prev, first, mid, last);

    if(prev != NULL && (root -> val < prev -> val))
    {
        if(first == NULL)
        {
            first = prev;
            mid = root;
        }
        else last = root;
    }

    prev = root;
    inOrderOpWay(root -> right, prev, first, mid, last);
}

void op_way(Node* root)
{
    Node* first = nullptr;
    Node* mid = nullptr;
    Node* last = nullptr;

    // Node* prev = new Node(INT_MIN);
    Node* prev = nullptr;
    inOrderOpWay(root, prev, first, mid, last);
    if(first && last) swap(first -> val, last -> val);
    else if(first && mid) swap(first -> val, mid -> val);
}

void print(Node* root)
{
    if(!root) return;
    print(root -> left);
    cout<<root -> val<<" ";
    print(root -> right);
}

int main()
{
    Node* root = new Node(3);
    root -> left = new Node(1);
    root -> right = new Node(4);
    root -> right -> left = new Node(2);

    // bru_way(root);
    op_way(root);
    print(root);
}