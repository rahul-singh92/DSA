#include <iostream>
using namespace std;

class q_imp {
    int qu[4];
    int cu_size = 0;
    int start = -1, end = -1;

    public:
        void push(int x)
        {
            if(cu_size == 4) cout<<"Cant push array is full.\n";
            else if(cu_size == 0)
            {
                start = 0, end = 0;
            }
            else
            {
                end = (end + 1) % 4;
            }
            qu[end] = x;
            cu_size++;
        }

        void pop()
        {
            if(cu_size==0) cout<<"Empty";
            if(cu_size == 1)
            {
                start
            }
        }
};

int main()
{

}