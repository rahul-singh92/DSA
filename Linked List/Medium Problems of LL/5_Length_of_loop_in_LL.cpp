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

int bru_way(Node* head)
{
    Node* temp = head;

    unordered_map<Node* , int> mpp;
    int count = 0;
    while(temp)
    {
        count++;
        if(mpp.find(temp) != mpp.end()) return count - mpp[temp] + 1;
        mpp[temp] = count;
        temp = temp -> next;
    }
    return 0;
}

int op_way(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
        {
            int count = 1;
            slow = slow -> next;
            while(slow != fast)
            {
                slow = slow -> next;
                count++;
            }
            return count + 1;
        }
    }
    return 0;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head -> next -> next -> next -> next = head;

    int ans = op_way(head);
    cout<<ans<<endl;
}