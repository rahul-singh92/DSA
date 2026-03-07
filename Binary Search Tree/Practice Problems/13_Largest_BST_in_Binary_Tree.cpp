#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int d) : val{d}, left{nullptr}, right{nullptr} {}
};

int largestBSTHelper(Node *root, int &minVal, int &maxVal, int &totalMax)
{
    if (!root)
    {
        minVal = INT_MAX;
        maxVal = INT_MIN;
        return 0;
    }

    int leftMin, leftMax, rightMin, rightMax;

    int leftSize = largestBSTHelper(root->left, leftMin, leftMax, totalMax);
    int rightSize = largestBSTHelper(root->right, rightMin, rightMax, totalMax);

    if (leftSize != -1 && rightSize != -1 && root->val > leftMax && root->val < rightMin)
    {

        minVal = min(root->val, leftMin);
        maxVal = max(root->val, rightMax);

        int currentSize = leftSize + rightSize + 1;
        totalMax = max(totalMax, currentSize);
        return currentSize;
    }
    minVal = INT_MIN;
    maxVal = INT_MAX;
    return -1;
}

int op_way(Node *root)
{
    int totalMax = 0;
    int minVal, maxVal;
    largestBSTHelper(root, minVal, maxVal, totalMax);
    return totalMax;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right = new Node(15);
    root->right->right = new Node(7);

    cout << "Size of largest BST: " << op_way(root) << endl;

    return 0;
}