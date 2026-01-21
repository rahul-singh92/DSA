#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int d, Node* n)
    {
        data = d;
        next = n;
    }
    Node(int d)
    {
        data = d;
    }
};

bool bru_way(Node* head)
{
    Node* temp = head;

    unordered_map<Node*, int> nodeMap;

    while(temp)
    {
        if(nodeMap.find(temp) != nodeMap.end()) return true;

        nodeMap[temp] = 1;

        temp = temp -> next;
    }
    return false;
}

bool op_way(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next)
    {   
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow) return true;
    }
    return false;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    // head -> next -> next -> next -> next = head;

    int ans = op_way(head);
    cout<<ans<<endl;
}