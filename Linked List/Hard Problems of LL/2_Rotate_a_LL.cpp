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

Node* bru_way(Node* head, int k)
{
    if(!head || !head -> next || k == 0) return head;
    
    for(int i = 0; i < k; i++)
    {
        Node* curr = head;
        Node* prev = NULL;

        while(curr -> next)
        {
            prev = curr;
            curr = curr -> next;
        }

        //Detach the last node and place it at the begining
        prev -> next = NULL;
        curr -> next = head;
        head = curr;
    }
    return head;
}

Node* opt_way(Node* head, int k)
{
    if(!head || !head -> next || k == 0) return head;

    int length = 1;
    Node* tail = head;
    while(tail -> next)
    {
        tail = tail -> next;
        length++;
    }

    tail -> next = head;
    
    //Traverse from the new tail (length - k - 1 from head)
    int stepToNewTail = length - k;
    Node* newTail = head;
    for(int i = 1; i < stepToNewTail; i++)
    {
        newTail = newTail -> next;
    }

    Node* newHead = newTail -> next;
    newTail -> next = NULL;

    return newHead;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = opt_way(head, 2);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}