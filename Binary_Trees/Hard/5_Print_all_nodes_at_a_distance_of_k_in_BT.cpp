#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int a): data(a), left(nullptr), right(nullptr) {}
};

void mapParentNodes(Node* root, unordered_map<Node* , Node*>& parentMap)
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();

        if(node -> left)
        {
            parentMap[node -> left] = node;
            q.push(node -> left);
        }

        if(node -> right)
        {
            parentMap[node -> right] = node;
            q.push(node -> right);
        }
    }
}

vector<int> bfsFromTarget(Node* target, unordered_map<Node*, Node*>& parentMap, int k)
{
    queue<Node*> q;
    unordered_set<Node*> visited;

    q.push(target);
    visited.insert(target);

    int cuLevel = 0;

    while(!q.empty())
    {
        int size = q.size();
        if(cuLevel++ == k) break;

        for(int i = 0; i< size; i++)
        {
            Node* node = q.front();
            q.pop();

            if(node -> left && visited.find(node -> left) == visited.end())
            {
                visited.insert(node -> left);
                q.push(node -> left);
            }

            if(node -> right && visited.find(node -> right) == visited.end())
            {
                visited.insert(node -> right);
                q.push(node -> right);
            } 

            if(parentMap.count(node) && visited.find(parentMap[node]) == visited.end())
            {
                visited.insert(parentMap[node]);
                q.push(parentMap[node]);
            }
        }
    }

    vector<int> result;
    while(!q.empty())
    {
        result.push_back(q.front() -> data);
        q.pop();
    }
    return result;
}

vector<int> distanceK(Node* root, Node* target, int k)
{
    if(!root) return {};
    unordered_map<Node*, Node*> parentMap;
    mapParentNodes(root, parentMap);

    return bfsFromTarget(target, parentMap, k);
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Node* target = root -> left;
    int k = 2;

    vector<int> result = distanceK(root, target, k);
    for(int val: result) cout<<val<<" ";
}