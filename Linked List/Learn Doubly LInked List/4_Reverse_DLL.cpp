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

Node* reverse_dll(Node* head)
{
    stack<int> st;
    Node* temp = head;
    while(temp)
    {
        st.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while(temp)
    {
        temp -> data = st.top();
        st.pop();
        temp = temp -> next;
    }
    return head;
}

Node* optimal_reverse(Node* head)
{
    if(head == NULL || head -> next == NULL) return head;
    Node* temp = head;
    Node* back = NULL;
    while(temp)
    {
        back = temp -> prev;
        temp -> prev = temp -> next;
        temp -> next = back;

        temp = temp -> prev;
    }
    return back -> prev;
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

    //Reverse using extreme sol
    // head = reverse_dll(head);

    //Reverse in single pass
    head = optimal_reverse(head);

    Node* temp = head;

    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}