#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int d)
    {
        val = d;
        next = nullptr;
    }
};

class LinkedList
{
    private:
        Node* head;
        int size;

    public:
        LinkedList()
        {
            head = NULL;
            size = 0;
        }

        void push(int x)
        {
            Node* element = new Node(x);

            element -> next = head;
            head = element;

            size++;
        }

        int pop()
        {
            if(head == NULL)
            {
                return -1;
            }

            int value = head -> val;
            Node* temp = head;
            head = head -> next;
            delete temp;

            return value;
        }

        int top()
        {
            if(head == NULL)
            {
                return -1;
            }

            return head -> val;
        }
};

int main()
{
    LinkedList st;

    st.push(6);
    st.push(5);
    cout<<st.pop()<<endl;
    cout<<st.top()<<endl;
}