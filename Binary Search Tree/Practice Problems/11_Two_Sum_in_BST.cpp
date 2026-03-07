#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int d): val{d}, left{nullptr}, right{nullptr} {}
};

void inOrderTraversal(Node* root, vector<int>& inorder)
{
    if(!root) return;
    inOrderTraversal(root -> left, inorder);
    inorder.push_back(root -> val);
    inOrderTraversal(root -> right, inorder);
}

bool bru_way(Node* root, int k)
{
    vector<int> inorder;

    inOrderTraversal(root, inorder);

    int l = 0, r = inorder.size() - 1;
    while(l < r)
    {
        int sum = inorder[l] + inorder[r];

        if(sum == k) return true; 

        else if(sum < k) l++;
        else r--;
    }
    return false;
}

//OP way
class BTSIterator
{
    private:
        stack<Node*> myStack;
        bool reverse;

        void pushAll(Node* root)
        {
            while(root != nullptr)
            {
                myStack.push(root);
                if(reverse)
                {
                    root = root -> right;
                }
                else root = root -> left;
            }
        }
    
    public:
        BTSIterator(Node* root, bool isReverse) : reverse{isReverse}
        {
            pushAll(root);
        }

        bool hasNext()
        {
            return !myStack.empty();
        }

        int next()
        {
            Node* tempNode = myStack.top();
            myStack.pop();

            if(!reverse) pushAll(tempNode -> right);

            else pushAll(tempNode -> left);

            return tempNode -> val;
        }
};

bool op_way(Node* root, int k)
{
    if(!root) return false;

    BTSIterator l(root, false);
    BTSIterator r(root, true);

    int i = l.next();
    int j = r.next();

    while(i < j)
    {
        if(i + j == k) return true;
        else if(i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
}

int main()
{
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    int target = 22;

    // bool exist = bru_way(root, target);
    bool exist = op_way(root, target);

    cout<<exist<<endl;
}