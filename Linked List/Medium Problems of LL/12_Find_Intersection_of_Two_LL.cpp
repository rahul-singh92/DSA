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
Node* bru_way(Node* head1, Node* head2)
{
    while(head2)
    {
        Node* temp = head1;
        while(temp)
        {
            if(temp == head2) return head2;
            temp = temp -> next;
        }
        head2 = head2 -> next;
    }
    return NULL;
}

Node* better_way(Node* head1, Node* head2)
{
    unordered_map<Node*, int> mpp;

    while(head1)
    {
        mpp[head1] = 1;
        head1 = head1 -> next;
    }
    while(head2)
    {
        if(mpp.find(head2) != mpp.end()) return head2;
        head2 = head2 -> next;
    }
    return NULL;
}

int getDifference(Node* head1, Node* head2) {
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            ++len1;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            ++len2;
            head2 = head2->next;
        }
    }
    return len1 - len2;  // If negative, length of list2 > length of list1, else vice-versa
}
Node* opt_way_1(Node* head1, Node* head2)
{
    int diff = getDifference(head1, head2);

    if(diff < 0)
        while(diff++ != 0) head2 = head2 -> next;
    else
        while(diff-- != 0) head1 = head1 -> next;

    while(head1)
    {
        if(head1 == head2) return head1;
        head2 = head2 -> next;
        head1 = head1 -> next;
    }
    return head1;
}

Node* opt_way_2(Node* head1, Node* head2)
{
    Node* d1 = head1;
    Node* d2 = head2;

    while(d1 != d2)
    {
        d1 = d1 == NULL ? head2 : d1 -> next;
        d2 = d2 == NULL ? head1 : d2 -> next;
    }
    return d1;
}

int main()
{
    Node* head1 = new Node(2);
    head1->next = new Node(1);
    head1->next->next = new Node(0);
    head1->next->next->next = new Node(1);
    head1->next->next->next->next = new Node(0);

    Node* head2 = new Node(5);
    head2 -> next = head1 -> next -> next;

    Node* ansNode = opt_way_2(head1, head2);

    if(ansNode) cout<<"Intersection found at "<<ansNode -> data<<endl;
    else cout<<"No Intersection\n";
}