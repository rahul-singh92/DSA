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

int op_way(Node* root)
{
    if(!root) return 0;

    int maxWidth = 0;

    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty())
    {
        int size = q.size();
        int minIndex = q.front().second;

        int first = 0;
        int last = 0;
        
        for(int i = 0; i < size; i++)
        {
            int curIndex = q.front().second - minIndex;
            Node* node = q.front().first;

            q.pop();

            if(i == 0) first = curIndex;

            if(i == size - 1) last = curIndex;

            if(node -> left) q.push({node -> left, 2*curIndex+1});
            if(node -> right) q.push({node -> right, 2*curIndex+2});
        }
        maxWidth = max(maxWidth, last - first + 1);
    }
    return maxWidth;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    int ans = op_way(root);
    cout<<ans<<endl;
}
