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

Node* delete_head(Node* head)
{
    if(head == NULL || head -> next == NULL) return NULL;
    Node* temp = head;
    head = head -> next;
    head -> prev = nullptr;
    free(temp);

    return head;
}

Node* delete_tail(Node* head)
{
    if(head == NULL || head -> next == NULL) return NULL;

    Node* temp = head;
    while(temp -> next)
    {
        temp = temp -> next;
    }
    temp -> prev -> next = nullptr;
    free(temp);
    return head;
}

Node* delete_k(Node* head, int k)
{
    if(head == NULL) return NULL;
    int count = 0;
    Node* kNode = head;
    while(kNode)
    {
        count++;
        if(count == k) break;
        kNode = kNode -> next;
    }

    if(kNode -> prev == NULL && kNode -> next == NULL) return NULL;
    else if(kNode -> prev == NULL) return delete_head(head);
    else if(kNode -> next == NULL) return delete_tail(head);
    kNode -> prev -> next = kNode -> next;
    kNode -> next -> prev = kNode -> prev;
    free(kNode);
    return head;
}

int main()
{
    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> prev = head;

    head -> next -> next = new Node(3);
    head -> next -> next -> prev = head -> next;

    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> prev = head -> next -> next;

    //Delete head
    // head = delete_head(head);

    //Delete tail
    // head = delete_tail(head);

    //Delete k
    head = delete_k(head, 2);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}