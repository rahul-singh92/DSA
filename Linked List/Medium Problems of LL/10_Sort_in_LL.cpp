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
    Node* temp = head;

    vector<int> v;

    while(temp)
    {
        v.push_back(temp -> data);
        temp = temp -> next;
    }
    sort(v.begin(), v.end());
    temp = head;
    for(int i = 0; i < v.size(); i++)
    {
        temp -> data = v[i];
        temp = temp -> next;
    }
    return head;
}

// Function to find middle of linked list
Node* findMiddle(Node* head) {
    // If list empty or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // Slow and fast pointers
    Node* slow = head;
    Node* fast = head->next;
    // Move fast twice as fast as slow
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Return middle node
    return slow;
}
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node
    Node* dummyNode = new Node(-1);
    
    // Temp pointer to build merged list
    Node* temp = dummyNode;
    // Traverse both lists
    while (list1 != nullptr && list2 != nullptr) {
        // Choose smaller node
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move temp pointer
        temp = temp->next;
    }
    // Attach remaining nodes
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return head of merged list
    return dummyNode->next;
}
Node* op_way(Node* head)
{
    if(head == NULL || head -> next == NULL) return head;

    Node* middle = findMiddle(head);
    
    Node* right = middle -> next;
    middle -> next = NULL;
    Node* left = head;

    left = op_way(left);
    right = op_way(right);

    return mergeTwoSortedLinkedLists(left, right);
}

int main()
{
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    head = op_way(head);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}