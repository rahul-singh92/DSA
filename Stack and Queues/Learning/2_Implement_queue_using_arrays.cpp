#include <iostream>
using namespace std;

class ArrayQueue
{
    private:
        int* arr;
        int start, end;
        int cur_size, max_size;

    public:
        ArrayQueue()
        {
            arr = new int[10];
            start = -1;
            end = -1;
            cur_size = 0;
            max_size = 10;
        }

        ~ArrayQueue()
        {
            delete[] arr;
        }

        void push(int x)
        {
            if(cur_size == max_size)
            {
                cout<<"Queue is full.\n";
                exit(1);
            }

            if(end == -1)
            {
                start = 0;
                end = 0;
            }
            else
            {
                end = (end + 1) % max_size;
            }

            arr[end] = x;
            cur_size++;
        }

        int pop()
        {
            if(start == -1)
            {
                cout<<"Queue is empty.\n";
                exit(1);
            }
            int popped = arr[start];

            if(cur_size == 1)
            {
                start = -1;
                end = -1;
            }
            else
            {
                start = (start + 1) % max_size;
            }
            cur_size--;
            return popped;
        }

        int peek()
        {
            if(start == -1)
            {
                cout<<"Queue is empty.\n";
                exit(1);
            }
            return arr[start];
        }
};

int main()
{
    ArrayQueue queue;
    queue.push(10);
    queue.push(5);
    cout<<queue.pop()<<endl;
    cout<<queue.peek()<<endl;
}