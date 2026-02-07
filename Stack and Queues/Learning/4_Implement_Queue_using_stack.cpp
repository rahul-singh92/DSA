#include <iostream>
using namespace std;

//Very Expensive for push operation
// class StackQueue
// {
//     private:
//         stack<int> st1, st2;

//     public:
//         StackQueue() {}

//         void push(int x)
//         {
//             while(!st1.empty())
//             {
//                 st2.push(st1.top());
//                 st1.pop();
//             }

//             st1.push(x);

//             while(!st2.empty())
//             {
//                 st1.push(st2.top());
//                 st2.pop();
//             }
//         }

//         int pop()
//         {
//             if(st1.empty())
//             {
//                 cout<<"Stack is Empty.\n";
//                 return -1;
//             }

//             int topElement = st1.top();
//             st1.pop();

//             return topElement;
//         }

//         int peek()
//         {
//             if(st1.empty())
//             {
//                 cout<<"Stack is Empty.\n";
//                 return -1;
//             }

//             return st1.top();
//         }
// };

//Better way
class StackQueue
{
    public:
        stack<int> input, output;
    public:
        StackQueue() {}

        void push(int x)
        {
            input.push(x);
        }

        int pop()
        {
            if(output.empty())
            {
                while(!input.empty())
                {
                    output.push(input.top());
                    input.pop();
                }
            }

            if(output.empty())
            {
                cout<<"Queue is empty.\n";
                return -1;
            }

            int x = output.top();
            output.pop();
            return x;
        }

        int peek()
        {
            if(output.empty())
            {
                while(!input.empty())
                {
                    output.push(input.top());;
                    input.pop();
                }
            }

            if(output.empty())
            {
                cout<<"Queue is Empty.\n";
                return -1;
            }

            return output.top();
        }
};

int main()
{
    StackQueue q;
    q.push(5);
    q.push(6);
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
}