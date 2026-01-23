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

Node* reverseLLIterative(Node* head)
{
    Node* prev = nullptr;
    Node* curr = head;

    while(curr)
    {
        Node* nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* Iterative_app(Node* head)
{
    head = reverseLLIterative(head);

    Node* current = head;

    //Initially carry is 1 because we want to add 1
    int carry = 1; 

    while(current && carry)
    {
        int sum = current -> data + carry;
        current -> data = sum % 10;
        carry = sum / 10;

        //If there is no next node and we still have a carry
        if(!current -> next && carry)
        {
            current -> next = new Node(carry);
            carry = 0;
        }
        current = current -> next;
    }

    head = reverseLLIterative(head);
    return head;
}

int addOneRecursive(Node* head)
{
    //Base Casse : When reaching beyond last node return carry 1
    if(!head) return 1;

    int carry = addOneRecursive(head -> next);
    int sum = head -> data + carry;
    head -> data = sum % 10;
    //Return new Carry
    return sum / 10;
}
Node* recursive_app(Node* head)
{
    int carry = addOneRecursive(head);

    if(carry)
    {
        Node* newHead = new Node(carry);
        newHead -> next = head;
        head = newHead;
    }
    return head;
}

int main()
{
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    head = recursive_app(head);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}