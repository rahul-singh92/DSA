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

Node* op_way(Node* head)
{
    Node* odd = head;
    Node* even = head -> next;
    Node* evenHead = head -> next;

    while(even && even -> next)
    {
        odd -> next = odd -> next -> next;
        even -> next = even -> next -> next;
        
        odd = odd -> next;
        even = even -> next;
    }
    odd -> next = evenHead;
    return head;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = op_way(head);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}