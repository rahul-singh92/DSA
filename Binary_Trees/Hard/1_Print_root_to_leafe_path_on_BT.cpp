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

bool getPath(Node* root, vector<int>& arr, int val)
{
    if(!root) return false;
    arr.push_back(root -> data);

    if(root -> data == val) return true;

    if(getPath(root -> left, arr, val) || getPath(root -> right ,arr, val)) return true;

    arr.pop_back();
    return false;
}

vector<int> op_way(Node* root, int val)
{
    vector<int> arr;
    if(!root) return arr;
    getPath(root, arr, val);
    return arr;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> ans = op_way(root, 5);
    
    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
}
