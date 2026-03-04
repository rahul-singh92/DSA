#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val(d), left(nullptr), right(nullptr) {}
};

vector<int> op_way(Node* root, int data)
{
    int floor = -1;
    int ceil = -1;
    if(!root) return {-1, -1};
    while(root)
    {
        if(root -> val == data)
        {
            floor = root -> val;
            ceil = root -> val;
        }
        if(root -> val > data)
        {
            ceil = root -> val;
            root = root -> left;
        }
        else
        {
            floor = root -> val;
            root = root -> right;
        }
    }
    return {floor, ceil};
}

int main()
{
    Node* root = new Node(10);
    root -> left = new Node(5);
    root -> right = new Node(15);
    root -> left -> left = new Node(2);
    root -> left -> right = new Node(6);

    vector<int> ans = op_way(root, 16);
    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
}