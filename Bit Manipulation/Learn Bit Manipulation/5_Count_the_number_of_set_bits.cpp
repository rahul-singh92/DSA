#include <iostream>
using namespace std;

int main()
{
    int n = 13;
    int count = 0;
    while(n > 1)
    {
        count += (n & 1);
        n = n >> 1;
        if(n == 1) count++;
    }
    cout<<count;

    //OR

    //Much faster way
    count = 0;
    while(n != 0)
    {
        n = n & (n - 1);
        count++;
    }
}