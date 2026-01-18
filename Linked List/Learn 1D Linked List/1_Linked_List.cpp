#include <iostream>
using namespace std;

struct Node {
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

Node* convert_array_to_ll(vector<int> &v)
{
    Node* head = new Node(v[0]);
    Node* mover = head;
    for(int i = 1; i < v.size(); i++)
    {
        Node* temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int length_of_ll(Node* head)
{
    int count = 0;
    Node* temp = head;
    while(temp)
    {
        temp = temp-> next;
        count++;
    }
    return count;
}

int checkIfPresent(Node* head, int value)
{
    Node* temp = head;
    while(temp)
    {
        if(temp -> data == value) return 1;
        temp = temp -> next;
    }
    return 0;
}

int main()
{
    vector<int> v ={1, 2, 3, 4};
    Node* x = new Node(v[0]);
    // cout<<x -> data;

    //or
    Node y = Node(v[1]);
    // cout<<y.data;

    //Convert
    Node* head = convert_array_to_ll(v);
    // cout<<head->data;

    //Linked List Traversal
    Node* temp = head;
    while(temp)
    {
        cout<<temp->data;
        temp = temp->next;
    }

    //Length of the linked list
    int length = length_of_ll(head);
    cout<<length;
}