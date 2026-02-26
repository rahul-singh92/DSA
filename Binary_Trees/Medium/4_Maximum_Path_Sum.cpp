#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

int dfs(Node* root, int& maxSum)
{
    if(!root) return 0;

    int left = max(0, dfs(root -> left, maxSum));
    int right = max(0, dfs(root -> right, maxSum));

    maxSum = max(maxSum, left + right + root -> data);

    return max(left, right) + root -> data;
}

int op_way(Node* root)
{
    int maxSum = INT_MIN;
    dfs(root, maxSum);
    return maxSum;
}

int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(5);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(6);

    int ans = op_way(root);

    cout<<ans<<endl;
}