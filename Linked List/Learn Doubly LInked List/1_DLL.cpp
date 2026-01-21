#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* back;

    Node(int d, Node* n, Node* b)
    {
        data = d;
        n = next;
        b = back;
    }
    Node(int d)
    {
        data = d;
        next = nullptr;
        back = nullptr;
    }
};

Node* con_to_dll(vector<int> arr)
{
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < arr.size(); i++)
    {
        temp -> next = new Node(arr[i]);
        temp -> next -> back = temp;
        temp = temp -> next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = con_to_dll(arr);

    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}