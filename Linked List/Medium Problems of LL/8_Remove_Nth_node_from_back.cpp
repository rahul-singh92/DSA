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

Node* bru_way(Node* head, int n)
{
    if(head == NULL) return NULL;

    int count = 0;
    Node* temp = head;

    while(temp)
    {
        count++;
        temp = temp -> next;
    }
    if(count == n)
    {
        Node* newHead = head -> next;
        free(head);
        return newHead;
    }

    int res = count - n;
    temp = head;
    while(temp)
    {
        res--;
        if(res == 0) break;
        temp = temp -> next;
    }

    Node* delNode = temp -> next;
    temp -> next = temp -> next -> next;
    free(delNode);
    return head;
}

Node* op_way(Node* head, int n)
{
    // Create a dummy node before head to handle edge cases
        Node* dummy = new Node(0, head);

        // Initialize slow and fast pointers at dummy
        Node* slow = dummy;
        Node* fast = dummy;

        // Move fast pointer N+1 steps ahead to create a gap
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow is now at node before target → delete target node
        slow->next = slow->next->next;

        // Return updated head
        return dummy->next;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = op_way(head, 2);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}