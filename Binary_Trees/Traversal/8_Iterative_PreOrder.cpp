#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> preOrder(Node* root)
{
    vector<int> ans;

    if(root == nullptr) return ans;

    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        root = st.top();
        st.pop();

        ans.push_back(root -> data);

        if(root -> right != nullptr)
        {
            st.push(root -> right);
        }
        if(root -> left != nullptr)
        {
            st.push(root -> left);
        }
    }
    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = preOrder(root);

    for(int val : result) 
    {
        cout << val << " ";
    }
    cout << endl;
}
