#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> levelOeder(Node* root)
{
    vector<vector<int>> ans;

    if(!root) return ans;

    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        vector<int> level;

        for(int i = 0; i < size; i++)
        {
            Node* node = q.front();
            q.pop();

            level.push_back(node -> data);

            if(node -> left) q.push(node -> left);

            if(node -> right) q.push(node -> right);
        }

        ans.push_back(level);
    }
    return ans;
}

vector<int> leftView(Node* root)
{
    vector<vector<int>> levels = levelOeder(root);

    vector<int> left;

    for(auto i: levels) left.push_back(i[0]);

    return left;
}

vector<int> rightView(Node* root)
{
    vector<vector<int>> levels = levelOeder(root);

    vector<int> right;

    for(auto i: levels) right.push_back(i.back());
    return right;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> left = leftView(root);
    for (int val : left) cout << val << " ";
    cout << "\n";

    vector<int> right = rightView(root);
    for (int val : right) cout << val << " ";
    cout << "\n";
}
