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

Node* delete_head(Node* head)
{
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    free(temp);
    // delete temp;
    return head;
}

Node* delete_tail(Node* head)
{
    if(head == NULL || head -> next == NULL) return NULL;
    Node* temp = head;
    while(temp -> next -> next)
    {
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = nullptr;

    return head;
}

Node* delete_k(Node* head, int k)
{
    if(head == NULL) return NULL;
    if(k == 1)
    {
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* prev;
    while(temp)
    {
        count++;
        if(count == k)
        {
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
int main()
{
    Node *head = new Node(5);
    head -> next = new Node(6);
    head -> next -> next = new Node(7);

    // Node* after_head_delete = delete_head(head);

    // Node* delete_tail_el = delete_tail(head);

    Node* delete_k_el = delete_k(head, 2);

    while(delete_k_el)
    {
        cout<< delete_k_el -> data << " ";
        delete_k_el = delete_k_el -> next;
    }
}