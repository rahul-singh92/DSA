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

bool search_ele(Node* head, int el)
{
    Node* temp = head;
    while(temp)
    {
        if(temp -> data == el) return true;
        temp = temp -> next;
    }
    return false;
}

int main()
{
    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);

    bool ans = search_ele(head, 0);
    cout<<ans<<endl;
}

hi hello