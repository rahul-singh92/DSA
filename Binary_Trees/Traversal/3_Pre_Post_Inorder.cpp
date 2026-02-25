#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> allTraversal(Node* root)
{
    vector<int> pre, in, post;

    if(root == NULL) return {};

    stack<pair<Node*, int>> st;

    st.push({root, 1});

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second == 1)
        {
            pre.push_back(it.first -> data);
            it.second = 2;
            st.push(it);

            if(it.first -> left != NULL)
            {
                st.push({it.first -> left, 1});
            }
        }

        else if(it.second == 2)
        {
            in.push_back(it.first -> data);
            it.second = 3;
            st.push(it);

            if(it.first -> right != NULL)
            {
                st.push({it.first -> right, 1});
            }
        }
        else
        {
            post.push_back(it.first -> data);
        }
    }

    vector<vector<int>> res;
    res.push_back(pre);
    res.push_back(in);
    res.push_back(post);
    return res;
}

int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> right -> right = new Node(5);

    vector<int> pre, in, post;

    vector<vector<int>> traversal = allTraversal(root);
}