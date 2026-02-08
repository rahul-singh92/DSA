#include <iostream>
using namespace std;

//Takes O(2n) space

// class MinStack {
//     private: 
//         stack<pair<int, int>> st;
    
//     public:
//         MinStack() {

//         }

//         void push(int x)
//         {
//             if(st.empty())
//             {
//                 st.push({x, x});
//                 return;
//             }
//             int mini = min(x, st.top().second);

//             st.push({x, mini});
//         }

//         void pop()
//         {
//             st.pop();
//         }

//         int top()
//         {
//             return st.top().first;
//         }

//         int getMin()
//         {
//             return st.top().second;
//         }
// };

class MinStack {
    private:
        stack<int> st;
        int mini;

    public:
        MinStack() { }

        void push(int value)
        {
            if(st.empty())
            {
                mini = value;
                st.push(value);
                return;
            }

            if(value > mini) st.push(value);
            else
            {
                st.push(2 * value - mini);
                mini = value;
            }
        }

        void pop()
        {
            if(st.empty()) return;

            int x = st.top();
            st.pop();

            if(x < mini)
            {
                mini = 2 * mini - x;
            }
        }

        int top()
        {
            if(st.empty()) return -1;

            int x = st.top();

            if(mini < x) return x;

            return mini;
        }

        int getMin()
        {
            return mini;
        }
};

int main()
{
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
}