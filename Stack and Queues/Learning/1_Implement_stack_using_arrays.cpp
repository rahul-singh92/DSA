#include <iostream>
using namespace std;

class stImp {
    public:
    int top = -1;
    int st[10];


    void push(int x)
    {
        if(top < 10)
        {
            top++;
            st[top] = x;
        }
    }

    int topp()
    {
        if(top == -1) return -1;
        return st[top];
    }

    void pop()
    {
        if(top == -1) cout<<"Cant pop"<<endl;
        else
        {
            top--;
        }
    }

    int size()
    {
        return top + 1;
    }
};

int main()
{
    stImp stt;
    stt.push(5);
    cout<<stt.topp()<<endl;
}