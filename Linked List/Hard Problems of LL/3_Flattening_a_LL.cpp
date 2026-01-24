#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *child;
    Node(int data) {
        val = data;
        next = NULL;
        child = NULL;
    }
};

/* Merge the two linked lists in a particular
 order based on the data value */
Node* merge(Node* list1, Node* list2)
{
    /* Create a dummy node as a 
    placeholder for the result */
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    
    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val < list2->val)
        {
            res->child = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            list2 = list2->child;
        }
        res = res -> child;
        res->next = NULL;
    }
    
    // Connect the remaining elements if any
    if(list1)
    {
        res->child = list1;
    } else 
    {
        res->child = list2;
    }
        
    return dummyNode->child;
}

// Function to flatten a linked list with child pointers 
Node* flattenLinkedList(Node* head) 
{
    // If head is null or there is no next node
    if(head == NULL || head->next == NULL)
    {
        return head; // Return head
    }
    
    head->next = flattenLinkedList(head->next);
    head = merge(head, head->next);

    return head;
}

int main() {
    Node* head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(15);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(22);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    Node* newH = flattenLinkedList(head);

    while(newH)
    {
        cout<<newH -> val<<" ";
        newH = newH -> child;
    }
}