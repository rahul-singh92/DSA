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

int bru_way(Node* head)
{
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
        if(st.top() != temp -> data) return false;
        st.pop();
        temp = temp -> next;
    }
    return true;
}

Node* reverseLinkedList(Node* head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;  // No change is needed; return the current head
    }

    // Recursive step: Reverse the remaining part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front' to reverse the link
    Node* front = head->next;

    // Update the 'next' pointer of 'front' to point to the current head
    front->next = head;

    // Set the 'next' pointer of the current head to null to break the original link
    head->next = NULL;

    // Return the new head obtained from the recursion
    return newHead;
}
int op_way(Node* head)
{
    if(head == NULL || head -> next == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    while(fast -> next && fast -> next -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* newHead = reverseLinkedList(slow -> next);

    Node* first = head;
    Node* second = newHead;

    while(second)
    {
        if(first -> data != second -> data)
        {
            reverseLinkedList(newHead);
            return false;
        }

        first = first -> next;
        second = second -> next;
    }

    reverseLinkedList(newHead);

    return true;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    int ans = op_way(head);
    cout<<ans<<endl;
}