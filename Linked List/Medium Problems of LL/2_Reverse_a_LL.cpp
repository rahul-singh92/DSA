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
    if(head == NULL || head -> next == NULL) return head;

    Node* temp = head;
    stack<int> st;
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

Node* optimal_way(Node* head)
{
    Node* temp = head;
    Node* prev = NULL;
    while(temp)
    {
        Node* ne = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = ne;
    }
    return prev;
}

Node* Recursive_way(Node* head)
{
    if(head == NULL || head -> next == NULL) return head;

    Node* newHead = Recursive_way(head -> next);

    Node* front = head -> next;

    front -> next = head;

    head -> next = NULL;

    return newHead;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    //Brute force where we put in stack then re put it
    // head = bru_way(head);

    //Optimal way in one loop by changing the pointers
    // head = optimal_way(head);

    //Recursive Way
    head = Recursive_way(head);
    
    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}