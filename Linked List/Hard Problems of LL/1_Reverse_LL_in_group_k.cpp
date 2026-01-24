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

Node* getKthNode(Node* head, int k)
{
    while(head && k > 0)
    {
        head = head -> next;
        k--;
    }
    return head;
}
Node* opt_way(Node* head, int k)
{
    Node* dummy = new Node(-1);
    dummy -> next = head;

    //Ponter to keep track of the prrevious group tail
    Node* prevGroup = dummy;

    while(true)
    {
        Node* kth = getKthNode(prevGroup, k);
        if(!kth) break;

        //Store the next group head
        Node* groupNext = kth -> next;

        //Break the chain to reverse k group
        Node* prev = groupNext;
        Node* curr = prevGroup -> next;

        //Reverse K node
        for(int i = 0; i < k; i++)
        {
            Node* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        //Connecting previous group to reversed
        Node* temp = prevGroup -> next;
        prevGroup -> next = kth;
        prevGroup = temp;
    }
    return dummy -> next;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = opt_way(head, 3);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}