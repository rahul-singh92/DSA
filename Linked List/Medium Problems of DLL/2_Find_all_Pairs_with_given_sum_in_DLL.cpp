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

unordered_map<int, int> bru_way(Node* head, int sum)
{
    unordered_map<int, int> mpp;
    Node* temp1 = head;
    while(temp1)
    {
        Node* temp2 = temp1 -> next;
        while(temp2 && (temp1 -> data + temp2 -> data <= sum))
        {
            if(temp1 -> data + temp2 -> data == sum)
            {
                mpp[temp1 -> data] = temp2 -> data;
            }
            temp2 = temp2 -> next;
        }
        temp1 = temp1 -> next;
    }
    return mpp;
}

unordered_map<int, int> opt_way(Node* head, int sum)
{
    Node* right = head;
    unordered_map<int, int> mpp;
    while(right -> next)
    {
        right = right -> next;
    }
    Node* left = head;

    while(right -> data > left -> data)
    {
        if(left -> data + right -> data == sum)
        {
            mpp[left -> data] = right -> data;
            left = left -> next;
            right = right -> prev;
        }
        else if(left -> data + right -> data < sum)
        {
            left = left -> next;
        }
        else
        {
            right = right -> prev;
        }
    }
    return mpp;
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

    unordered_map<int, int> ans = opt_way(head, 4);

    for(auto i : ans)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
}