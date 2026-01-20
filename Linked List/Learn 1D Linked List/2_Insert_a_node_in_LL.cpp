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
        next = nullptr;
    }
};

Node* insert_at_head(Node* head, int el)
{
    return new Node(el, head);
}

Node* insert_at_last(Node* head, int el)
{
    if(head == NULL) return new Node(el);
    Node* temp = head;

    while(temp -> next)
    {
        temp = temp -> next;
    }
    temp -> next = new Node(el);
    return head;
}

Node* insert_k(Node* head, int el, int k)
{
    if(head == NULL && k == 1) return new Node(el);
    if(k == 1) return new Node(el, head);

    int count = 0;
    Node* temp = head;
    while(temp)
    {
        count++;
        if(count == k - 1)
        {
            Node* x = new Node(el);
            x -> next = temp -> next;
            temp -> next = x;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

int main()
{
    Node* head = new Node(2);
    head -> next = new Node(3);
    head -> next -> next = new Node(4);

    // head = insert_at_head(head, 1);
    // head = insert_at_last(head, 5);

    head = insert_k(head, 7, 3);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<< " ";
        temp = temp -> next;
    }
}