#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int v): val(v), left{nullptr}, right{nullptr} {}
};

string serialize(Node* root)
{
    if(!root) return "";

    string s = "";

    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        Node* curNode = q.front();
        q.pop();

        if(curNode == nullptr) s += "#,";
        else
        {
            s += to_string(curNode -> val) + ",";
            q.push(curNode -> left);
            q.push(curNode -> right);
        }
    }
    return s;
}

Node* deserialize(string data)
{
    if(data.empty()) return nullptr;
    stringstream s(data);
    string str;

    getline(s, str, ',');

    Node* root = new Node(stoi(str));

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        getline(s, str, ',');

        if(str != "#")
        {
            Node* leftNode = new Node(stoi(str));
            node -> left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');

        if(str != "#")
        {
            Node* rightNode = new Node(stoi(str));
            node -> right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

void inorder(Node* root)
{
    if(!root) return;

    inorder(root -> left);
    cout<<root -> val<<" ";
    inorder(root -> right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string serialised = serialize(root);
    cout<<serialised<<endl;

    Node* deserialise = deserialize(serialised);

    inorder(deserialise);
    cout<<endl;
}