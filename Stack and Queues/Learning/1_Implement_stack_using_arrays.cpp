#include <iostream>
using namespace std;

class ArrayStack
{
    private:
        int* stackArr;
        int capacity;
        int topIndex;

    public:
        ArrayStack(int size = 1000)
        {
            capacity = size;
            stackArr = new int[capacity];
            topIndex = -1;
        }

        ~ArrayStack()
        {
            delete[] stackArr;
        }

        void push(int x)
        {
            if(topIndex >= capacity - 1)
            {
                cout<<"Stack Overflow\n";
                return;
            }
            stackArr[++topIndex] = x;
        }

        int pop()
        {
            if(topIndex == -1)
            {
                cout<<"Stack is Empty\n";
                return -1;
            }
            return stackArr[topIndex--];
        }

        int top()
        {
            if(topIndex == -1) 
            {
                cout<<"Stack is empty\n";
                return -1;
            }
            return stackArr[topIndex];
        }
};

int main()
{
    ArrayStack stack;
    stack.push(5);
    stack.push(10);
    cout<<stack.pop()<<" ";
    cout<<endl<<stack.top()<<endl;
}