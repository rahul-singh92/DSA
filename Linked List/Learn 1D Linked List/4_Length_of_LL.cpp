#include <iostream>
using namespace std;

struct Node
{
    int data;;
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

int length_LL(Node* head)
{
    Node* temp = head;
    int count = 0;
    while(temp)
    {
        count++;
        temp = temp -> next;
    }
    return count;
}

int main()
{
    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);

    int len = length_LL(head);

    cout<<len<<endl;
}