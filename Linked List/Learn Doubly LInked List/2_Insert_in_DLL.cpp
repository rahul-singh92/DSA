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

Node* insert_head(Node* head, int data)
{
    if(head == NULL) return new Node(data);

    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    return temp;
}

Node* insert_tail(Node* head, int data)
{
    if(head == NULL) return new Node(data);
    
    Node* temp = head;
    while(temp -> next) temp = temp -> next;

    temp -> next = new Node(data);
    temp -> next -> prev = temp;
    return head;
}

Node* insert_k(Node* head, int data , int k)
{
    if(k == 1) return insert_head(head, data);

    Node* temp = head;
    int count = 0;
    while(temp)
    {
        count++;
        if(count == k) break;
        temp = temp -> next;
    }
    Node* newNode = new Node(data, temp, temp -> prev);
    temp -> prev -> next = newNode;
    temp -> prev = newNode;
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

    //Insert at head
    // head = insert_head(head, 10);

    //Insert at tail
    // head = insert_tail(head, 10);

    //Insert at k
    head = insert_k(head, 10, 2);

    Node* temp = head;

    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}