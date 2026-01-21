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

int find_middle(Node* head)
{
    if(head == NULL) return -1;

    Node* temp = head;
    int count = 0;
    while(temp)
    {
        count++;
        temp = temp -> next;
    }
    int mid = count / 2 + 1;
    temp = head;
    count = 0;
    while(temp)
    {
        count++;
        if(count == mid) return temp -> data;
        temp = temp -> next;
    }
    return -1;
}

int op_way(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast && fast -> next)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow -> data;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    //Extreme way
    // int ans = find_middle(head);

    //Better way
    int ans = op_way(head);
    cout<<ans<<endl;
}