#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

void buildGraph(Node* node, Node* parent, unordered_map<int, vector<int>>& graph)
{
    if(!node) return;

    if(parent)
    {
        graph[node -> data].push_back(parent -> data);
        graph[parent -> data].push_back(node -> data);
    }

    buildGraph(node -> left, node, graph);
    buildGraph(node -> right, node, graph);
}

int minTime(Node* root, int target)
{
    unordered_map<int, vector<int>> graph;
    buildGraph(root, nullptr, graph);

    unordered_set<int> visited;

    queue<int> q;
    q.push(target);
    visited.insert(target);

    int time = 0;

    while(!q.empty())
    {
        int size = q.size();
        bool burned = false;

        for(int i = 0; i < size; i++)
        {
            int node = q.front();
            q.pop();

            for(int neighbour: graph[node])
            {
                if(!visited.count(neighbour))
                {
                    visited.insert(neighbour);
                    q.push(neighbour);
                    burned = true;
                }
            }
        }
        if(burned) time++;
    }
    return time;
}

void mapParentNodes(Node* root, unordered_map<Node*, Node*>& parentMap)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
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

int bfsFromTarget(Node* target, unordered_map<Node*, Node*>& parentMap)
{
    queue<Node*> q;
    unordered_set<Node*> visited;

    q.push(target);
    visited.insert(target);

    int time = 0;

    while(!q.empty())
    {
        int size = q.size();
        bool burnedNewNode = false;

        for(int i = 0; i < size; i++)
        {
            Node* node = q.front();
            q.pop();

            if(node -> left && !visited.count(node -> left))
            {
                burnedNewNode = true;
                visited.insert(node -> left);
                q.push(node -> left);
            }

            if(node -> right && !visited.count(node -> right))
            {
                burnedNewNode = true;
                visited.insert(node -> right);
                q.push(node -> right);
            }

            if(parentMap.count(node) && !visited.count(parentMap[node]))
            {
                burnedNewNode = true;
                visited.insert( parentMap[node]);
                q.push(parentMap[node]);
            }
        }
        if(burnedNewNode == true) time++;
    }
    return time;
}

int op_way(Node* root, Node* target)
{
    if(!root) return 0;
    unordered_map<Node*, Node*> parentMap;
    mapParentNodes(root, parentMap);

    return bfsFromTarget(target, parentMap);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->right = new Node(7);

    
    int ans = op_way(root, root);
    cout<<ans<<endl;
}