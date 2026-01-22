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

    int count = 0;

    while(temp)
    {
        count++;
        temp = temp -> next;
    }

    int middle = count / 2;

    temp = head;
    while(temp)
    {
        middle--;

        if(middle == 0)
        {
            Node* middle = temp -> next;
            temp -> next = temp -> next -> next;

            free(middle);
            break;
        }
        temp = temp -> next;
    }
    return head;
}

Node* op_way(Node* head)
{
    Node* slow = head;
    Node* fast = head -> next -> next;

    while(fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* delNode = slow -> next;
    slow -> next = slow -> next -> next;
    free(delNode);
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