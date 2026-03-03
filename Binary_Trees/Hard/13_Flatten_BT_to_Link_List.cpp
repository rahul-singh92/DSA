#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val(d), left(nullptr), right(nullptr) {}
};

Node* previ = nullptr;

void bru_way(Node* root)
{
    if(root == nullptr) return;
    bru_way(root -> right);
    bru_way(root -> left);

    root -> right = previ;
    root -> left = nullptr;
    previ = root;
}

void bet_way(Node* root)
{
    if(root == nullptr) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node* cur = st.top();
        st.pop();

        if(cur -> right != nullptr) st.push(cur -> right);
        if(cur -> left != nullptr) st.push(cur -> left);
        if(!st.empty()) cur -> right = st.top();
        cur -> left = nullptr;
    }
}

void op_way(Node* root)
{
    Node* cur = root;
    while(cur)
    {
        if(cur -> left)
        {
            Node* pre = cur -> left;
            while(pre -> right) pre = pre -> right;
            
            pre -> right = cur -> right;
            cur -> right = cur -> left;
            cur -> left = NULL;
        }
        cur = cur -> right;
    }
}

void print(Node* root)
{
    if(!root) return;
    cout<<root -> val<<" ";
    print(root -> right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->right->right = new Node(7);
    root->right->left = new Node(8);

    // bru_way(root);
    // bet_way(root);
    op_way(root);
    print(root);
}