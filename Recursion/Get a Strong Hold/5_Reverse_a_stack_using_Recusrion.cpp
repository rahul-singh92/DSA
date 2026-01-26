#include <iostream>
using namespace std;

void insert_at_bottom(stack<int>& s, int top)
{
    if(s.empty())
    {
        s.push(top);
        return;
    }

    int topVal = s.top();
    s.pop();

    insert_at_bottom(s, top);

    s.push(topVal);
}

void reverseStack(stack<int>& s)
{
    if(s.empty()) return;

    int top = s.top();
    s.pop();

    reverseStack(s);

    insert_at_bottom(s, top);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}