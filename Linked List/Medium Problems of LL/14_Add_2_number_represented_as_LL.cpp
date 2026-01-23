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

Node* op_way(Node* head1, Node* head2)
{
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    int carry = 0;

    while((head1 || head2) || carry)
    {
        int sum = 0;
        if(head1)
        {
            sum += head1 -> data;
            head1 = head1 -> next;
        }
        if(head2)
        {
            sum += head2 -> data;
            head2 = head2 -> next;
        }
        //Carry gets add to the sum
        sum += carry;
        carry = sum / 10;
        Node* node = new Node(sum % 10);
        temp -> next = node;
        temp = temp -> next;
    }
    return dummy -> next;
}

int main()
{
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    Node* result = op_way(head1, head2);

    Node* temp = result;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}