#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int d) : val{d}, left{nullptr}, right{nullptr} {}
};

void inOrderTraversal(Node *root, vector<int> &inorder)
{
    if (!root)
        return;
    inOrderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inOrderTraversal(root->right, inorder);
}

int binarySearch(vector<int> &arr, int key)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left == (int)arr.size() ? -1 : left;
}

vector<int> bru_way(Node *root, int key)
{
    vector<int> inorder;
    inOrderTraversal(root, inorder);
    int idx = binarySearch(inorder, key);
    if (idx == -1)
        return {-1, -1};

    int pred = (idx == 0) ? -1 : inorder[idx - 1];
    int suc = (idx == inorder.size() - 1) ? -1 : inorder[idx + 1];
    return {pred, suc};
}

vector<int> bet_way(Node* root, int key)
{
    Node* successor = nullptr;
    Node* predecessor = nullptr;
    Node* curr = root;

    while(curr != nullptr)
    {
        if(curr -> val == key)
        {
            if(curr -> left)
            {
                Node* temp = curr -> left;
                while(temp -> right) temp = temp -> right;
                predecessor = temp;
            }

            if(curr -> right)
            {
                Node* temp = curr -> right;
                while(temp -> left) temp = temp -> left;
                successor = temp;
            }
            break;
        }
        else if(curr -> val > key)
        {
            successor = curr;
            curr = curr -> left;
        }
        else
        {
            predecessor = curr;
            curr = curr -> right;
        }
    }

    int pred = predecessor ? predecessor -> val : -1;
    int suc = successor ? successor -> val : -1;

    return {pred, suc};
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    int key = 6;
    // vector<int> ans = bru_way(root, key);
    vector<int> ans = bet_way(root, key);

    if (ans[0] == -1)
        cout << "NULL ";
    else
        cout << ans[0] << " ";

    if (ans[1] == -1)
        cout << "NULL";
    else
        cout << ans[1];
}