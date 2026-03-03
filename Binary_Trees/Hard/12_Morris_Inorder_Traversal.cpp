#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val(d), left(nullptr), right(nullptr) {}
};

vector<int> op_way(Node* root)
{
    vector<int> ans;
    Node* cur = root;

    while(cur != NULL)
    {
        if(cur -> left == NULL)
        {
            ans.push_back(cur -> val);
            cur = cur -> right;
        }
        else
        {
            Node* prev = cur -> left;
            while(prev -> right && prev -> right != cur) prev = prev -> right;

            if(prev -> right == NULL)
            {
                prev -> right = cur;
                cur = cur -> left;
            }
            else
            {
                prev -> right = NULL;
                ans.push_back(cur -> val);
                cur = cur -> right;
            }
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
    root->left->right->right = new Node(6);

    vector<int> inorder = op_way(root);

    for(auto i: inorder) cout<<i<<" ";
    cout<<endl;
}
