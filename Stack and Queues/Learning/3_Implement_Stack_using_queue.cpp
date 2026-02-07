#include <iostream>
using namespace std;

class QueueStack
{
    private:
        queue<int> q;
    
    public:
        void push(int x)
        {
            int s = q.size();
            q.push(x);

            for(int i = 0; i < s; i++)
            {
                q.push(q.front()); //As top is still the first we will take all elemnt from starr and put itt back
                q.pop();
            }
        }

        int pop()
        {
            int n = q.front();
            q.pop();
            return n;
        }

        int top()
        {
            return q.front();
        }

        bool isEmpty()
        {
            return q.empty();
        }
};

int main()
{
    QueueStack st;
    st.push(5);
    st.push(6);
    cout<<st.pop()<<endl;
    cout<<st.top()<<endl;
}