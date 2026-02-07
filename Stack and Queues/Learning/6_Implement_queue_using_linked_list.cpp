#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

class LinkedList
{
    private:
        Node* start;
        Node* end;
        int size;
    
    public:
        LinkedList()
        {
            start = end = nullptr;
            size = 0;
        }

        void push(int x)
        {
            Node* element = new Node(x);

            if(start == NULL)
            {
                start = end = element;
            }
            else
            {
                end -> next = element;
                end = element;
            }
            size++;
        }

        int pop()
        {
            if(start == NULL) return -1;

            int value = start -> val;
            Node* temp = start;
            start = start -> next;
            delete temp;
            size--;

            return value;
        }

        int peek()
        {
            if(start == NULL) return -1;

            return start -> val;
        }
};

int main()
{
    LinkedList q;
    q.push(5);
    q.push(6);
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
}