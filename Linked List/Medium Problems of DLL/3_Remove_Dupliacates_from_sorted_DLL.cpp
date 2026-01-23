#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int d, Node* n, Node* p)
    {
        data = d;
        next = n;
        prev = p;
    }
    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

Node* opt_way(Node* head)
{
    if(head == NULL) return nullptr;

    Node* temp = head;
    
    while(temp && temp -> next)
    {
        Node* nextNode = temp -> next;

        if(nextNode && temp -> data == nextNode -> data)
        {
            Node* dupNode = nextNode;
            nextNode = nextNode -> next;
            free(dupNode);

            temp -> next = nextNode;
            if(nextNode) nextNode -> prev = temp;
        }
        temp = temp -> next;
    }
    return head;
}

int main()
{
    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> prev = head;

    head -> next -> next = new Node(2);
    head -> next -> next -> prev = head -> next;

    head -> next -> next -> next = new Node(3);
    head -> next -> next -> next -> prev = head -> next -> next;

    head = opt_way(head);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}