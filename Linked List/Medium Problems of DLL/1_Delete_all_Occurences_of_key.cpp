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

Node* delete_k(Node* head, int k)
{
    Node* prev = nullptr;
    Node* temp = head;

    while(temp)
    {
        if(temp -> data == k) 
        {
            if(temp == head) head = head -> next;
            Node* nextNode = temp -> next;
            prev = temp -> prev;

            if(nextNode) nextNode -> prev = prev;
            if(prev) prev -> next = nextNode;

            free(temp);
            temp = nextNode;
        }
        else
        {
            temp = temp -> next;
        }
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

    head -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> prev = head -> next -> next;

    head = delete_k(head, 2);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}