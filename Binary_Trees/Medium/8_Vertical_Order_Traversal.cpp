#include <iostream>
#include <map>
#include <set>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> findVertical(Node* root)
{
    map<int, map<int, multiset<int>>> nodes;

    queue<pair<Node*, pair<int, int>>> todo;

    todo.push({root, {0, 0}});

    while(!todo.empty())
    {
        auto p = todo.front();
        todo.pop();

        Node* temp = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(temp -> data);

        if(temp -> left) todo.push({temp -> left, {x - 1, y + 1}});

        if(temp -> right) todo.push({temp -> right, {x + 1, y + 1}});
    }

    vector<vector<int>> ans;

    for(auto p: nodes)
    {
        vector<int> col;
        for(auto q: p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<vector<int>> verticalTraversal = findVertical(root);

    for(auto i: verticalTraversal)
    {
        for(auto v: i) cout<<v<<" ";
        cout<<endl;
    }

    return 0;
}
