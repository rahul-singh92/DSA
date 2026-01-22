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

Node* bru_way(Node* head)
{
    Node* temp = head;

    unordered_map<Node* , int> mpp;
    while(temp)
    {
        if(mpp.find(temp) != mpp.end()) return temp;
        mpp[temp] = 1;
        temp = temp -> next;
    }
    return NULL;
}

Node* op_way(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head -> next -> next -> next -> next = head;

    Node* ans = op_way(head);
    cout<<((ans) ? ans -> data : NULL)<<endl;
}