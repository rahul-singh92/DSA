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
    Node* zeroDummy = new Node(-1);
    Node* oneDummy = new Node(-1);
    Node* twoDummy = new Node(-1);

    Node* zeroTail = zeroDummy;
    Node* oneTail = oneDummy;
    Node* twoTail = twoDummy;

    Node* temp = head;

    while(temp)
    {
        if(temp -> data == 0)
        {
            zeroTail -> next = temp;
            zeroTail = zeroTail -> next;
        }
        else if(temp -> data == 1)
        {
            oneTail -> next = temp;
            oneTail = oneTail -> next;
        }
        else
        {
            twoTail -> next = temp;
            twoTail = twoTail -> next;
        }
        temp = temp -> next;
    }

    zeroTail -> next = oneDummy -> next ? oneDummy -> next : twoDummy -> next;
    oneTail -> next = twoDummy -> next;
    twoTail -> next = nullptr;

    head = zeroDummy -> next;

    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;

    return head;
}

int main()
{
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    head = op_way(head);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}